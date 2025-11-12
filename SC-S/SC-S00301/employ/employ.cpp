#include <bits/stdc++.h>
using namespace std;
const int N=1000,mod=998244353;

int n,m;
string s;
int a[N];

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin >>s;
	int cnt=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (!a[i])
			cnt++;
	}
	cout <<cnt*(cnt-1)%mod;
	return 0;
}