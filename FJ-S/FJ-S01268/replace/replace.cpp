#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define N 200010
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;continue;
		}
		int len=t1.length();
		string diff="";
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i])diff+=t1[i];
		}
		for(int i=1;i<=n;i++){
			int p=s1[i].find(diff);
			if(p!=-1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

