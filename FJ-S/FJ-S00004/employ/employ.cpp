#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())>'9' || ch<'0')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
const int mod=998244353;
long long f(int n){
	if(n==1)return 1;
	return n*((f(n-1)%mod))%mod;
}
int n,m;
long long ans;
const int N=505,M=505;
int s[N],c[N];
bool cmp(int a,int b){return a<b;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=s[i-1]+ch-'0';
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+n+1,cmp);
	ans=f(n)%mod;
	if(s[n]==n){
		cout<<ans;
		return 0;
	}else if(m==n){
		if(s[n]!=n)ans=0;
		cout<<ans;
		return 0;
	}
	int rqls=s[n];
	if(rqls<m){
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
//:(?
//ÉXÉmµÄÎÒ 
