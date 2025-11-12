//ccf orz
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
int n,m,c[555],mod=998244353,ans=1,cnt;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>s;
	for(int i=1;i<=n;i++) c[i]=read();
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i]>i){
			ans*=n;
			ans%=mod;
			cnt++;
		}
	}
	if(cnt>=m){
		cout<<(ans*cnt)%mod;
		exit(0);
	}
	cout<<ans;
	return 0;
}
