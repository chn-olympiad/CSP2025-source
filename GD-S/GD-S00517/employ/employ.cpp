#include<bits/stdc++.h>
#define fo(i,x,y) for(register int i=(x);i<=(y);++i)
using namespace std;
const int mod=998244353;
int a[501],c[501],d[501]={1},n,m,t;
bool b[501];
string s;
void dg(const int x,const int y,const int z){
	if(y+n-x+1<m)
		return;
	if(y>=m){
		t=(t+d[n-x+1])%mod;
		return;
	}
	if(x>n)
		return;
	fo(i,1,n)
		if(!b[i]){
			b[i]=1;
			dg(x+1,y+(s[x-1]=='1'&&c[x]+z<a[i]),z+(s[x-1]=='1'&&c[x]+z>=a[i]));
			b[i]=0;
		}
}
void print(const int a){
	if(a>9)
		print(a/10);
	putchar(a%10|48);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	fo(i,1,n){
		cin>>a[i];
		d[i]=1ll*d[i-1]*i%mod;
	}
	fo(i,0,n-1)
		c[i+1]=c[i]+(s[i]=='0');
	if(m==n){
		if(c[n])
			putchar('0');
		else
			print(d[n]);
		return 0;
	}
	dg(1,0,0);
	print(t);
	return 0;
}
