#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 5e5+50;
using namespace std;
int n,k,cnt,ans,an;
int a[N];
int vis[N];
void dfs(int l,int r,int x){
	cnt=max(cnt,x);
	for(int i=1;i<=n;i++){
		for(int j=l;j<=r;j++){
			if((vis[j+i]^vis[j])==k&&j+i<=n){
				dfs(j+i,r,x+1);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		vis[i]+=vis[i-1];
		vis[i]^=a[i];
		ans+=a[i];
		if(a[i]==a[i+1]&&(i&1)&&a[i]==0&&i!=n) an++;
	}
	if(ans==0){
		if(k==0){
			cout <<n <<endl;
			return 0;
		}
		if(k==1){
			cout <<0 <<endl;
			return 0;
		}
	}
	if(k==1){
		cout <<ans <<endl;
		return 0;
	}
	dfs(0,n,0);
	cout <<cnt <<endl;
	return 0;
}


