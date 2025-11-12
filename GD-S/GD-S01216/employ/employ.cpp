#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int maxn=506;
int n,m,c[maxn];
int M,flag[maxn];
ll ans;
string s;
int dg(int day,int OK,int RE,int met){
	int ris=1,vis=0;
	if(c[met]<=RE) ris=0,vis=1;
	else if(s[day-1]=='0') ris=0,vis=1;
	if(day==n&&OK+ris>=m) ans++,ans%=mod;
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		flag[i]=1;
		dg(day+1,OK+ris,RE+vis,i);
		flag[i]=0;
	}  
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) M++;
	}
	for(int i=0;i<n;i++){//对于sp:a 
		if(s[i]=='0') break;
		if(i==n-1){
			ans=1;
			for(int i=1;i<=n-M;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
			return 0;
		}
	}
	if(m==n){//对于m==n 
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		flag[i]=1;
		dg(1,0,0,i);
		flag[i]=0;
	}
	cout<<ans;
	return 0;
}
