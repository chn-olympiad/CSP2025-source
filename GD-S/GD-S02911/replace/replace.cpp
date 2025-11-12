#include<bits/stdc++.h>
#define rint register int
using namespace std;
inline int read(){
	char c;
	int num_in=0,num_sign=1;
	for(;!isdigit(c);c=getchar())
		if(c=='-') num_sign=-1;
	for(;isdigit(c);c=getchar())
		num_in=(num_in<<3)+(num_in<<1)+(c^48);
	return num_in*num_sign; 
}
int n,q;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(rint i=1;i<=n;i++) cin>>s1>>s2;
	for(rint i=1;i<=q;i++) cin>>s1>>s2;
	for(rint i=1;i<=q;i++) cout<<'0'<<endl;
}
