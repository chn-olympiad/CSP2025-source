// GZ-S00383 贵阳市第一中学 胡祺然
#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,b[4],tot[5],mx,my,ans,tx,ty;
struct node{
	int ma,mi,m1,m2;
}a[N];
bool cmp(node x,node y){
	return (x.ma-x.mi)>(y.ma-y.mi);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		tot[1]=0;
		tot[2]=0;
		tot[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			mx=-1;
			my=-1;
			cin>>b[1]>>b[2]>>b[3];
			for(int j=1;j<=3;j++){
				if(b[j]>mx){
					my=mx;
					ty=tx;
					mx=b[j];
					tx=j;
				}
				else if(b[j]>my){
					my=b[j];
					ty=j;
				}
			}
			a[i].ma=mx;
			a[i].mi=my;
			a[i].m1=tx;
			a[i].m2=ty;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(tot[a[i].m1]==(n/2)){
				tot[a[i].m2]++;
				ans+=a[i].mi;
			}else{
				tot[a[i].m1]++;
				ans+=a[i].ma;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
