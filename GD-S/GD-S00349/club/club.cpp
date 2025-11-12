#include<bits/stdc++.h>
using namespace std;
int in(){
	int a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())a=(a<<1)+(a<<3)+c-'0';
	return a*f;
}
const int N=1e5+5;
int a[N],b[N],c[N];
vector<int> d[3];
int n,t;
long long ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		n=in();
		ans=0;
		for(int i=0;i<3;i++)d[i].clear();
		for(int i=1;i<=n;i++){
			a[i]=in();
			b[i]=in();
			c[i]=in();
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				d[0].push_back(a[i]-max(b[i],c[i]));
			}else if(b[i]>a[i]&&b[i]>=c[i]){
				ans+=b[i];
				d[1].push_back(b[i]-max(a[i],c[i]));
			}else{
				ans+=c[i];
				d[2].push_back(c[i]-max(b[i],a[i]));
			}
		}n=n>>1;
		for(int i=0;i<3;i++){
			if(d[i].size()>n){
				sort(d[i].begin(),d[i].end());
				for(int j=0;j<d[i].size()-n;j++)
					ans-=d[i][j];
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
