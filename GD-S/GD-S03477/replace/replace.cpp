#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll int
#define ri register int
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline ll read(){
	ll r=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<1)+(r<<3)+(c^48);
		c=getchar();
	}
	return r*f;
}
inline ll Min(ll a,ll b){
	return a<b?a:b;
}
inline ll Max(ll a,ll b){
	return a>b?a:b;
}
const int N=2e5+5;
int n,q,maxx=-1;
string s1[N],s2[N];
string t1,t2;
string h1,h2,p;
inline int FI(string a,int k,int len){
	string b;
	if(k==1) for(int i=0;i<len;i++) b[i]=h1[i];
	if(k==2) for(int i=0;i<len;i++) b[i]=h2[i];
	for(int i=0;i<a.size();i++){
		int j=0;
		for(j=0;j<len;j++)
			if(a[i+j]!=b[j]) break;
		if(j==len) return i+1;
	}
	return false;
}
inline int FIr(string a,string b,int len){
	for(int i=0;i<a.size();i++){
		int j=0;
		for(j=0;j<len;j++)
			if(a[i+j]!=b[j]) break;
		if(j==len) return i+1;
	}
	return false;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],maxx=Max(maxx,s1[i].size());
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()>maxx){
			puts("0");
			continue;
		}
		if(t2.size()>maxx){
			puts("0");
			continue;
		}
		int ans=0,l,r;
		for(int j=0;j<t1.size();j++)
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		for(int j=t1.size()-1;j>=0;j--)
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
		int len=r-l+1;
		for(int j=0;j<=r-l;j++) h1[j]=t1[j+l];
		for(int j=0;j+l<=r;j++) h2[j]=t2[j+l];
		for(int j=1;j<=n;j++){
			int w=FI(s1[j],1,len);
			int e=FI(s2[j],2,len);
			if(!w||!e) continue;
			if(w!=e) continue;
			for(int k=0;k<w;k++)
				p[k]=s1[j][k];
			if(FIr(t1,p,w)==l-w) continue;
			for(int k=0;k<e;k++)
				p[k]=s2[j][k];
			if(FIr(t2,p,e)==l-w) continue;
			for(int k=w+len;k<s1[j].size();k++)
				p[k]=s1[j][k];
			if(FIr(t1,p,s1[j].size()-w-len)==t1.size()-r) continue;
			for(int k=w+len;k<s2[j].size();k++)
				p[k]=s2[j][k];
			if(FIr(t2,p,s2[j].size()-w-len)==t2.size()-r) continue;
			ans++;
		}
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
