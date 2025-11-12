#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll t,cnt[4]={0};
struct data{
	ll x,y,z;
}d[maxn];
bool cmp(data x,data y){
	if(x.x==y.x) return x.y>y.y;
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 	
	cin>>t;
	while(t--){
		ll n,qzh[maxn][4]={0};
		cin>>n;
		ll a[maxn][4],sum=0;
		bool tp1=1,tp2=1;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				qzh[i][j]=qzh[i-1][j]+a[i][j];
			}/*d[i].x=a[i][1];
			d[i].y=a[i][2];
			d[i].z=a[i][3];*/
			if(a[i][2] || a[i][3]) tp1=0;
			else if(a[i][3]) tp2=0;
		}if(n==2){
			for(ll i=1;i<=3;i++){
				for(ll j=1;j<=3;j++){
					sum=max(sum,a[1][j]+a[1][i]);
				}
			}
		}
		else{
			if(tp1){
				ll a1[maxn];
				for(ll i=1;i<=n;i++)
					a1[i]=a[i][1];
				sort(a1+1,a1+1+n);
				for(ll i=n;i>n/2;i--)
					sum+=a1[i];
			}/*else if(tp2){
				sort(d+1,d+1+n,cmp);
				for()	
			}*/
			else{
				ll l1=1,r3=n;
				for(ll r1=2;r1<n/2;r1++){
					ll l2=r1;
					for(ll r2=l2+1;r2-l2+1<=n/2 && n-r2+1<=n/2;r2++){
						ll l3=r2;
						for(ll i=1;i<=3;i++){
							for(ll j=1;j<=3;j++){
								if(j==i) continue;
								for(ll k=1;k<=3;k++){
									if(k==i || k==j) continue;
									sum=max(sum,qzh[r3][i]-qzh[l3-1][i]+qzh[r2][j]-qzh[l2-1][j]+qzh[r1][k]-qzh[l1-1][k]);
								}
							}
						}
					}
				}
			}/**/
		}cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
