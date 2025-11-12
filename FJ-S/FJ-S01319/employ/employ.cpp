#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e2+5;
int f[N],a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) a[i]=read(),f[i]=i;
	int ans=0;
	if(n<=10){
		do{
			int fl=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt<a[f[i]]) fl+=(s[i]=='1'),cnt+=(s[i]=='0');
				else ++cnt;
			}
			ans+=(fl>=m);
		}while(next_permutation(f+1,f+n+1));
		write(ans);
	}
	else{
		long long res=1;
		for(int i=1;i<=n;i++) res*=i,res%=998244353;
		write(res);
	}
	return 0;
}


