#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,q;
int ans;
string s1,s2;
unordered_map<string,string> f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		f[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		ans=0;
		for(int len=1;len<s1.size();len++)
			for(int j=0;j+len-1<s1.size();j++){
				string sub1=s1.substr(j,len);
				string temp=s1;
				s1.replace(j,len,f[sub1]);
				if (s1==s2)ans++;
				s1=temp;
			}
		if (f[s1]==s2)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
