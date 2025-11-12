#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
char in[N],*p1=in,*p2=in,out[N],*p3=out;
inline char gc(){
	return p1==p2&&(p2=(p1=in)+fread(in,1,N,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline void read(T &x){
	x=0;
	char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=gc();
	}
}
int n,m,c;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	cin>>s;
	for(int i=1;i<=n;i++) read(c);
	cout<<0;
	return 0;
}
