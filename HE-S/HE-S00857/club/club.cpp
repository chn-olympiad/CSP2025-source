#include<bits/stdc++.h>
using namespace std;
#define zhiyinni return
#define shizaishi 0
#define taimei ;
#define int long long
int T,n;
struct ovo{
	int d1,d2,d3,ca,d;
}a[100010];
bool cmp1(ovo x,ovo y){return x.ca>y.ca;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int z,y,x;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d1>=a[i].d2 and a[i].d1>=a[i].d3){
				a[i].d=1;a[i].ca=a[i].d1-a[i].d2+a[i].d1-a[i].d3;
			}else if(a[i].d2>=a[i].d1 and a[i].d2>=a[i].d3){
				a[i].d=2;a[i].ca=a[i].d2-a[i].d1+a[i].d2-a[i].d3;
			}else{
				a[i].d=3;a[i].ca=a[i].d3-a[i].d1+a[i].d3-a[i].d2;
			}
		}
		sort(a+1,a+1+n,cmp1);
		x=0,y=0,z=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].d==1){
				if(x<n/2) ans+=a[i].d1,x++;
				else{
					if(a[i].d2>a[i].d3) ans+=a[i].d2,y++;
					else ans+=a[i].d3,z++;
				}
			}else if(a[i].d==2){
				if(y<n/2) ans+=a[i].d2,y++;
				else{
					if(a[i].d1>a[i].d3) ans+=a[i].d1,x++;
					else ans+=a[i].d3,z++;
				}
			}else{
				if(z<n/2) ans+=a[i].d3,z++;
				else{
					if(a[i].d1>a[i].d2) ans+=a[i].d1,x++;
					else ans+=a[i].d2,y++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	zhiyinni shizaishi taimei
}
