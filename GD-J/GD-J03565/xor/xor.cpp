#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,x,num,a[100010],k,k1,l,r,y,mid;
map<long long,int > mp;
vector<int> v[1000100];
void dfs(int x,int l){
	ans=max(ans,l*1LL);
	for(int i=x+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k) dfs(j,l+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	} 
	dfs(0,0);
	cout<<ans;
}

