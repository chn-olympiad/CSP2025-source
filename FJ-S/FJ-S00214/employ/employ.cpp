#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=503,MOD=998244353;
int n,m,c[N],ans;
string str;
inline void dfs(int sum[],int nsum,bool o[]){
	if(nsum==n){
		int cnt1=0,cnt2=0;
		for(int i=0;i<n;i++){
			if(sum[i]<=cnt1||str[i]=='0')cnt1++;
			else cnt2++;
		}
		if(cnt2>=m)ans++,ans%=MOD;
		return ;
	}
	for(int i=0;i<n;i++){
		if(!o[i]){
			sum[nsum]=c[i];
			o[i]=1,dfs(sum,nsum+1,o),o[i]=0;
		}
	}
}
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>str;
	for(int i=0;i<n;i++)cin >>c[i];
	sort(c,c+n);
	int sum[n+3]={};
	bool o[n+3]={};
	for(int i=0;i<n;i++)o[i]=1,sum[0]=c[i],dfs(sum,1,o),o[i]=0;
	cout <<ans;
	return 0;
}
