#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL n;
LL k[4];
struct people{
	LL w[4];
	LL com;
};
people p[N];
bool cmp(people a,people b){
	return a.com>b.com;
}
LL ans=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(k,0,sizeof k);
		memset(p,0,sizeof p);
		ans=0;

		cin>>n;
		for(int i=1;i<=n;i++){
			LL a[4];
			for(int j=1;j<=3;j++){
				cin>>p[i].w[j];
				a[j]=p[i].w[j];
			}
			sort(a+1,a+4);
			p[i].com=a[3]-a[2];
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			LL a[4];
			for(int j=1;j<=3;j++){
				if(k[j]<n/2){
					a[j]=p[i].w[j];
				}
				else a[j]=-1;
			}
			sort(a+1,a+4);
			for(int j=1;j<=3;j++){
				if(a[3]==p[i].w[j]){
					ans+=a[3];
					k[j]++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
