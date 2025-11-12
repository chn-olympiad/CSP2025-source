#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10,mod=998244353;

int n,m,a[N],c[N];

int fd[N],summ,jc[N];

bool vis[N];

inline void dfs(int le,int x,int js){
//	cout<<1;
	if(le>n){
		if(x>=m){
			summ++;
			summ%=mod;
		} 
		return;
	}
	if(x>=m){
		summ+=jc[n-le+1];
		summ%=mod;
		return;
	}
	
	if(m-x>n-le+1)return;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(a[le]==1&&c[i]>js){
//				cout<<1;
				dfs(le+1,x+1,js);
			}
			else
				dfs(le+1,x,js+1);
			vis[i]=0;
		}
	return;
}
signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int sum=0,pd=1,sl=0;
	cin>>n>>m;
	jc[1]=1;
	for(int i=2;i<=n;i++)jc[i]=i*jc[i-1]%mod;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1')a[i]=1;
		else pd=0;
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)sl++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	
	if(m==n){
		if(sl){
			cout<<0;
			return 0;
		}
		int ll=1;
		for(int i=1;i<=n;i++){
			ll*=i;
			ll%=mod;
		}
		cout<<ll;
		return 0;
	}
	
	if(m==1){
		sort(c+1,c+n+1);
		int s=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1){
				for(int j=1;j<=n;j++)
					if(c[j]>=i)s++;
				break;
			}
		for(int i=1;i<n;i++){
			s*=i;
			s%=mod;
		}
		cout<<s;
	}
	
//	if(pd){
//		for(int i=1;i<=n;i++)
//			fd[c[i]-1]++;
//		for(int i=n;i>=1;i--)
//			fd[i]+=fd[i]-1;
//		for(int i=1;i<=sl;i++){
//			for(int j=1;j<=fd[i];j++)
//		}
//	}
	dfs(1,0,0);
	cout<<summ;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
