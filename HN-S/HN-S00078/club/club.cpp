#include <bits/stdc++.h>
//#define int long long
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
const int N=1e5+7;
typedef long long lglg;
struct node{
	int a,b,c;
}s[N];
bool cmp(node A,node B){
	return max(A.a,max(A.b,A.c))>max(B.a,max(B.b,B.c));
}
bool cmp2(node A,node B){
	return A.a-max(A.b,A.c)<B.a-max(B.b,B.c);
}
bool cmp3(node A,node B){
	return A.b-max(A.a,A.c)<B.b-max(B.a,B.c);
}
bool cmp4(node A,node B){
	return A.c-max(A.b,A.a)<B.c-max(B.b,B.a);
}
int n;
int cnt1,cnt2,cnt3;
node sa[N],sb[N],sc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//不要注释掉，不要打错文件名，测完大样例要改回来 
	int _=read();
	while(_--){
		cnt1=cnt2=cnt3=0;
		n=read();
		lglg ans=0;
		for(int i=1;i<=n;i++){
			s[i].a=read();
			s[i].b=read();
			s[i].c=read();
			ans+=max(s[i].a,max(s[i].b,s[i].c));
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].a>=max(s[i].b,s[i].c)){
				sa[++cnt1]=s[i];
			}
			else if(s[i].b>=max(s[i].a,s[i].c)){
				sb[++cnt2]=s[i];
			}
			else if(s[i].c>=max(s[i].a,s[i].b)){
				sc[++cnt3]=s[i];
			}
		}
		if(cnt1>n/2){
			sort(sa+1,sa+cnt1+1,cmp2);
			for(int i=1;i<=cnt1-n/2;i++){
				ans-=(sa[i].a);
				ans+=max(sa[i].b,sa[i].c);
			}
		}
		else if(cnt2>n/2){
			sort(sb+1,sb+cnt2+1,cmp3);
			for(int i=1;i<=cnt2-n/2;i++){
				ans-=(sb[i].b);
				ans+=max(sb[i].a,sb[i].c);
			}
		}
		else if(cnt3>n/2){
			sort(sc+1,sc+cnt3+1,cmp4);
			for(int i=1;i<=cnt3-n/2;i++){
				ans-=(sc[i].c);
				ans+=max(sc[i].b,sc[i].a);
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
Ren5Jie4Di4Ling5%
By C_0_a4S
Luogu_uid=1424067
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

竟然花了半小时 
expect:100pts
*/

