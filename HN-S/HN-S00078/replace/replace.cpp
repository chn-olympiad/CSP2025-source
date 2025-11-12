#include <bits/stdc++.h>
//#define int long long
using namespace std;

//int read(){
//	int x=0,f=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		f|=ch=='-';ch=getchar();
//	}
//	while(ch>='0'&&ch<='9'){
//		x=(x<<1)+(x<<3)+(ch^48);
//		ch=getchar();
//	}
//	return f?-x:x;
//}
typedef long long lglg;
typedef unsigned long long ulglg;
//多测清空
//不要把变量搞混，特别是i和j
//不要看错数据范围
//读题！
//对完样例要对拍
//时间不够了就老老实实打暴力吧
const int N=5e6+7;
const ulglg p=131;

ulglg h[N],th[N],pw[N];
ulglg geth(int l,int r){
	return h[r]-h[l-1]*pw[r-l+1];
}
ulglg getth(int l,int r){
	return th[r]-th[l-1]*pw[r-l+1];
}
//char s1[N],s2[N],t1[N],t2[N];
struct hsh{
	int len;
	ulglg val,toval;
}c[200005];
bool cmp(hsh A,hsh B){
	return A.len<B.len;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//不要注释掉，不要打错文件名，测完大样例要改回来 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5e6+1;i++){
		pw[i]=pw[i-1]*p;
	}
	string s1,s2;
	for(int i=1;i<=n;i++){
		
		cin>>s1>>s2;
		s1="?"+s1;
		s2="?"+s2;
		int l=s1.size()-1;
		ulglg h1=0,h2=0;
		for(int j=1;j<=l;j++){
			h1=h1*p+s1[j];
			h2=h2*p+s2[j];
		}
		c[i].len=l;
		c[i].val=h1;
		c[i].toval=h2;
	} 
	sort(c+1,c+1+n,cmp);
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		t1="?"+t1;
		t2="?"+t2;
		int lenn=t1.size()-1;
		for(int i=1;i<=lenn;i++){
			h[i]=h[i-1]*p+t1[i];
			th[i]=th[i-1]*p+t2[i];
		}
		long long ans=0;
		int l=1,r=0;
		for(int i=1;i<=lenn;i++){
			if(t1[i]!=t2[i]){
				l=i;break;
			}
			
		}
		for(int i=lenn;i;i--){
			if(t1[i]!=t2[i]){
				r=i;break;
			}
		}
		for(int i=n;i;i--){
			if(c[i].len<r-l+1)	break;
			int mn=c[i].len-(r-l+1);
			for(int j=1;j+c[i].len-1<=lenn;j++){
				if(geth(j,j+c[i].len-1)==c[i].val&&getth(j,j+c[i].len-1)==c[i].toval){
					ans++;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
//	cout<<(geth(2,4)==geth(5,7));
	return 0;
}
/*
我补药烤串口牙 
空间 2GiB?????????????? 
算我求你了别卡hash 
By C_0_a4S
Luogu_uid=1424067
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

O(nqlen)
expect:
不卡hash的话25pts 
太少了，就比朴素暴力高一点 
*/


