#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=550;
const ll mod=998244353;
ll n,m,c[N],cnt,ans;
bool fg=1;
string s;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10),putchar(x%10+48);}
	return;
}
void solve1(){
	ll sum=1,p[50];
	for(ll i=1;i<=n;i++)sum*=i,p[i]=i;
	while(sum--){
		cnt=0;
		for(ll i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
			}
			if(s[i]=='0')cnt++;
		}
		if(n-cnt>=m)ans++;
		next_permutation(p+1,p+n+1);
	}
	write(ans);
	return;
}
void solve2(){
	for(ll i=1;i<=n;i++){
		if(c[i]>0)ans++;
	}
	if(ans<m)putchar('0');
	else{
		ll res=1;
		for(int i=2;i<=n;i++)res=(res*i)%mod;
		write(res);
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	s=' '+s;
	for(ll i=1;i<=n;i++)c[i]=read();
	if(n<=10){
		solve1();
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(s[i]=='0')fg=0;
	}
	if(fg){
		solve2();
		return 0;
	}
	if(m==1){
		ll res=1;
		for(int i=2;i<=n;i++)res=(res*i)%mod;
		write(res);
		return 0;
	}
	if(m==n)putchar('1');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
