#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
int n,m;
const int N=500,mod=998244353;
int s[N],c[N],p[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	char ch=getchar();
	for(int i=1;i<=n;i++){
		while(!isdigit(ch)) ch=getchar();
		s[i]=ch-'0';
		ch=getchar();
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	/*bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]==0) flag=0;
	}
	if(flag){
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cnt++;
				continue;	
			}
			if(c[i]>cnt) num++;
		}
		if(num<m){
			cout<<0;
			return 0;
		}
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
			}
			cout<<ans;
			return 0;
		}
	}*/
	int ans=0;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	do{
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0||cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(s[i]==1){
				num++;
			}
		}
		if(num>=m){
			ans=(ans+1)%mod;
		}
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
