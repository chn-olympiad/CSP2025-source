#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e5+5;
typedef pair<string,string> PSS;
typedef long long LL;
LL ans;
int n,q;
PSS t[N],s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i].x>>s[i].y;
	for(int i=1;i<=q;i++)cin>>t[i].x>>t[i].y;
	for(int i=1;i<=q;i++){
		ans=0;
		if((int)t[i].x.size()!=(int)t[i].y.size()){printf("0\n");continue;}
		for(int j=1;j<=n;j++){
			string tmp=t[i].x;
			if(t[i].x.find(s[j].x)!=string::npos){
				tmp.replace(t[i].x.find(s[j].x),(int)s[j].x.size(),s[j].y);
				if(tmp==t[i].y)ans++;
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
	}
