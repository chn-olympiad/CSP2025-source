#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],n,k,ans;

vector<int>vec[N];

int dfs(int l,int r,int v){
	if(l==r)return 1;
	for(int i=l;i<=r;i++){
		for(int j=0;j<vec[i].size() && vec[i][j]<=r;j++){
			v=max(1+dfs(l,i-1,0)+dfs(vec[i][j]+1,r,0),v);
		}
	}
	return v;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				vec[i].push_back(j);
			}
		}
	}
	cout << dfs(1,n,0);
	return 0;
}
