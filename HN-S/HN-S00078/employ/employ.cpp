#include <bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
//多测清空
//不要把变量搞混，特别是i和j
//不要看错数据范围
//读题！
//对完样例要对拍
//时间不够了就老老实实打暴力吧
/*
 10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
const int N=500+7,mod=998244353;
char s[N];
int c[N];
int p[N];
typedef long long lglg;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//不要注释掉，不要打错文件名，测完大样例要改回来 
	int n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		c[i]=read();
		p[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)	cnt+=(s[i]=='1');
//	if(cnt==n){
//		int fcnt=0;
//		for(int i=1;i<=n;i++){
//			if(c[i]==0)	fcnt++;
//		}
//		int ans=1;
//		for(int i=1;i<=n;i++){
//			ans=(ans*i)%mod;
//		}
//		printf("%lld\n",(n-fcnt>=m)?ans:0);
//	} 
	if(n<=10){
		int k=0;
		int suc=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||k>=c[p[i]]){
				k++; 
			} 
			else	suc++;
		}
		if(suc>=m)	ans=(ans+1)%mod;
		while(next_permutation(p+1,p+1+n)){
			k=0;
			suc=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||k>=c[p[i]]){
					k++; 
				} 
				else	suc++;
			}
			if(suc>=m)	ans=(ans+1)%mod;
		}
		printf("%lld\n",ans);
	}
	else{
		puts("0");
	}
	return 0;
}
/*
By C_0_a4S at 18:22 
Luogu_uid=1424067
考场电脑线太松了，黑了两次屏 

expect:8+eps pts

Expect:100+72+25+8=205pts
1=肯定是丢了的
 2=有没有吧
 希望有蓝√ 
再见 
freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
*/


