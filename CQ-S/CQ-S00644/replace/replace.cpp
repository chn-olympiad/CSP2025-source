#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
int n,m,ans;
string a[200100],b[200010];
string x,y;
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		ans=0;
		cin>>x>>y;
		string u=x;
		for(int i=1;i<=n;i++){
			int tmp=x.find(a[i]);
			if(tmp==-1)continue;
			int len=x.length(),p=a[i].length();
			for(int k=tmp,j=0;k<len && j<p;k++,j++){
				x[k]=b[i][j];
			}	
//			cout<<x<<' ';
			if(x==y)ans++;		
			x=u;
		}
		printf("%lld\n",ans);

	}
	return 0;
}


