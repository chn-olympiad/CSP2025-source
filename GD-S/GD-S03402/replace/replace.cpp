#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,i,j,l,r;
string a[200005],b[200005],c,d,e,f,g,h;
map<pair<string,string>,bool>vis;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)cin>>a[i]>>b[i],vis[{a[i],b[i]}]=1;
	while(m--){
		cin>>c>>d,ans=0;
		if(c.size()!=d.size()){
			printf("0\n");
			continue;
		}
		if(c==d){
			for(i=1;i<=n;i++)
				if(a[i]==b[i]&&c.find(a[i])<c.size())
					ans++;
			printf("%lld\n",ans);
			continue;
		}
		l=0,r=c.size()-1,e=f="";
		while(c[l]==d[l])l++;
		while(c[r]==d[r])r--;
		for(i=l;i<=r;i++)e=e+c[i],f=f+d[i];
		for(i=l;i>=0;i--){
			if(i!=l)e=c[i]+e,f=d[i]+f;
			g=e,h=f;
			for(j=r;j<c.size();j++){
				if(j!=r)g=g+c[j],h=h+d[j];
				if(vis[{g,h}])ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
