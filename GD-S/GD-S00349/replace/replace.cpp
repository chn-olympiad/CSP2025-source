#include<bits/stdc++.h>
using namespace std;
int in(){
	int a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())a=(a<<1)+(a<<3)+c-'0';
	return a*f;
}
const int N=2e5+7;
int n,q;
int a[N],b[N],lb[N];
int ta[N],tb[N],ltb[N];
string s;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in();
	q=in();
	for(int i=1;i<=n;i++){
		cin>>s;b[i]=s.length();
		for(int j=0;j<b[i];j++)if(s[j]=='b'){a[i]=j;break;}
		cin>>s;
		for(int j=0;j<b[i];j++)if(s[j]=='b'){a[i]-=j;break;}
	}
	for(int i=1;i<=q;i++){
		cin>>s;tb[i]=s.length();
		for(int j=0;j<tb[i];j++)if(s[j]=='b'){ta[i]=j;break;}
		cin>>s;
		for(int j=0;j<tb[i];j++)if(s[j]=='b'){ta[i]-=j;break;}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(ta[i]==a[i]&&tb[i]>=b[i])ans++;
		}cout<<ans<<"\n";
	}
	return 0;
}
