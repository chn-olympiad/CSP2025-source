#include <bits/stdc++.h>
#define maxn 505
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[maxn],id[maxn],fac[maxn],mul[maxn];
int ans=1;
char x;
bool s[maxn];
void solve1(){
	int cnt=0,pos=1,num=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			cnt++;
			while(pos<=n&&c[pos]<i) pos++,num++;
			if(num==0){
				ans=0;
				break;
			}
			ans=ans*num%mod;
			num--;
		}
	}
	cout<<(fac[n]-ans*fac[n-cnt]%mod+mod)%mod;
}
void solve2(){
	sort(s+1,s+n+1);
	if(c[1]==0||s[1]==0) cout<<"0";
	else cout<<fac[n];
}
void solve3(){
	int ans=0;
	for(int i=1;i<=n;i++) id[i]=i;
	do{
		int pre=0,num=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				if(c[id[i]]>pre) num++;
				else pre++;
			}
			else pre++;
		}
		if(num>=m) ans++;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x,s[i]=x-'0',sum+=s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	fac[0]=fac[1]=1;
	for(int i=2;i<=maxn-5;i++) fac[i]=fac[i-1]*i%mod; 
	if(m==1) solve1();
	else if(m==n) solve2();
	else solve3();
	cout.flush();
	fclose(stdin);
	fclose(stdout);
} 
