#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,flag,ans,p[200100],l,r,a[200100],b[200100],c[200100],d[200100],cnt,anss[200100],u,v,w;
string s[200100],t[200100],x,y,o[2100],q[2100],tmp;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];p[i]=s[i].size();flag+=p[i];
	}
	if(flag<=1000&&n<=1000){
//	if(flag<=1&&n<=1){
		while(m--){
			cin>>x>>y;
			if(x.size()!=y.size()){
				cout<<0<<"\n";continue;
			}
			k=x.size();x=" "+x;o[0]=q[k+1]="";ans=0;
			for(int i=1;i<=k;i++){
				o[i]=o[i-1]+x[i];
			}
			for(int i=k;i>=1;i--){
				q[i]=q[i+1]+x[i];
			}
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(k-i+1<p[j])continue;
					tmp="";
					for(int kk=i;kk<=i+p[j]-1;kk++)tmp+=x[kk];
					if(tmp!=s[j])continue;
					if(o[i-1]+t[j]+q[i+p[j]]==y)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	} 
	else{
		for(int i=1;i<=n;i++){
			l=r=0;
			for(int j=0;j<p[i];j++){
				if(s[i][j]=='b')l=j;
				if(t[i][j]=='b')r=j;
			}
			a[i]=min(l,r);
			b[i]=p[i]-1-max(l,r);
			c[i]=l-r;
		}
		for(int i=1;i<=m;i++){
			cin>>x>>y;k=x.size();
			if(x.size()!=y.size()){
				cout<<0<<"\n";continue;
			}
			else{
				l=r=0;ans=0;
				for(int j=0;j<k;j++){
					if(x[j]=='b')l=j;
					if(y[j]=='b')r=j;
				}
				u=min(l,r);
				v=k-1-max(l,r);
				w=l-r;
				for(int j=1;j<=n;j++){
					if(a[j]<=u&&b[j]<=v&&c[j]==w)ans++;
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

5 5
aaaab baaaa
aabaa abaaa
aba baa
ab ba
ba ab
aaaab baaaa
abaaa aaaba
aaaaaaaaaaaaaaaaaabaaa aaaaaaaaaaaaaaaaabaaaa
aaaaaaaaaaaaaaaaaabaaa aaaaaaaaaaaaaaaaaabaaa
aaaabaaaaa aaaaabaaaa
*/
