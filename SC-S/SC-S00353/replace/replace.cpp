#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) x&-x
const int N=2e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
int n,q,pres,sufs,preq,sufq,l1,l2;
ll ans=0;
string s1[N],s2[N];
string q1,q2;
bool ch(int st,string sx,string sy,string qx,string qy){
	for(int i=0;i<sx.length();i++){
		if(sx[i]!=qx[st+i] || sy[i] !=qy[st+i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){		
		cin>>q1>>q2;
		ans=0,preq=0,sufq=q1.length()-1;
		while(q1[preq]==q2[preq]) preq++;
		while(q1[sufq]==q2[sufq]) sufq--;
		for(int j=1;j<=n;j++){
			l1=s1[j].length(),l2=q1.length(),sufs=l1-1;
			while(s1[j][sufs]==s2[j][sufs]) sufs--;
			if(l1>l2 || l1<sufq-preq+1) continue;
			for(int s=max(sufq-l1+1,0);s<=min(l2-l1,preq);s++){
				if(s1[j][0]!=q1[s] || s2[j][0]!=q2[s]) continue;
				if(ch(s,s1[j],s2[j],q1,q2)) ans++;
			}
		} 
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/