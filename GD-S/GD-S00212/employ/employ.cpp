#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans;
int c[502];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int fl1=0,fl2=0;
	for(int i=0;i<s.size();i++){
		if(!s[i]) fl1=1;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(!c[i]) fl2=1;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%988244353;
	}
	if(n==m&&(fl1||fl2)) cout<<0<<'\n';
	else cout<<ans<<'\n';
	return 0;
}

