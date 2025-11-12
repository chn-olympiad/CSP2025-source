#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0){
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
#define mod 998244353
int n,m,s[505],c[505],ord[505],sum,ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		char c=getchar();
		s[i]=c-48;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	for(int i=1;i<=n;i++){
		ord[i]=i;
	}
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[ord[i]]){
				cnt++;
			}
			else if(!s[i]){
				cnt++;
			}
			else{
				sum++;
			}
		}
		ans=(ans+(sum>=m))%mod;
	}while(next_permutation(ord+1,ord+n+1));
	write(ans);
	return 0;
}
