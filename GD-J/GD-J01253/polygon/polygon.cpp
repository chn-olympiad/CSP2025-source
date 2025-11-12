//#Shang4Shan3Ruo6Shui4
//998244353
#include<bits/stdc++.h>
using namespace std;
//struct rr{
//	int n,m;
//	operator<(rr x)const{
//		return m<x.m;
//	}
//};
//priority_queue<rr> h;
#define int long long
int n,s[5005][5005],k[5005],pd,sumn;
int pdl[5005];
void dfs(int t){
	if(t==n+1){
		int maxn=-50000;
		int ck=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,pdl[i]);
			ck+=pdl[i];
		}
		if(ck>maxn*2)sumn++;
		sumn=sumn%998244353;
		return;
	}
	dfs(t+1);
	pdl[t]=k[t];
	dfs(t+1);
	pdl[t]=0;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]!=1)pd=1;
	}
	if(pd==0){
		s[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int o=0;o<=i;o++){
				s[i][o]=s[i-1][o]+s[i-1][o-1];//在i个数里选o个
				s[i][o]=s[i][o]%998244353;
			}
		}
		int ans=0; 
		for(int i=3;i<=n;i++){
			ans=ans+s[n][i];
//			cout<<n<<' '<<i<<' '<<s[n][i]<<endl;
			ans=ans%998244353;
		}
		cout<<ans%998244353;
	}
	else {
		dfs(1);
		cout<<sumn%998244353;
	}
//	h.push((rr){1,1});
//	h.push((rr){2,2});
//	cout<<h.top().n;
//	h.pop();
//	cout<<h.top().n;
	return 0;
}
