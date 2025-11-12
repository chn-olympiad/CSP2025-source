#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const ll MOD=998244353;
const int N=505;
int n,m;
char s[N];
int c[N];
int a[N];
void work1()
{
	for(int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&i-1-cnt<c[a[i]]){
				cnt++;			                       
			}
		}                              
		if(cnt>=m) ans++;
	}while(next_permutation(a+1,a+n+1)); 
	cout<<ans<<'\n';
}		
void work2()
{
	bool flag=true;
	for(int i=1;i<=n;i++) if(s[i]!='1'||c[i]==0) {flag=false;break;}
	if(!flag) {cout<<0<<'\n';return ;}
	ll ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans<<'\n';
}
void work3()
{
	int cnt=0; 
	for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
	cout<<cnt<<'\n';
	if(n-cnt>=m){
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%MOD;
		cout<<ans<<'\n';
	}
	else cout<<0<<'\n';
}
void work4()
{
	int cnt=0; 
	for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
	if(cnt==)
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++) {cin>>s[i];if(s[i]!='1') flag=false;}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) work1(); //yes
	else if(m==n) work2(); //yes
	else cout<<0<<'\n';
}
