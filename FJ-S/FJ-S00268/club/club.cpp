#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,ans,lim,mx,x[N][5],l[5]={0};
struct d{
	int a,f;
}d[N][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,l[1]=0,l[2]=0,l[3]=0;
		cin>>n;
		lim=n/2;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>x[i][1]>>x[i][2]>>x[i][3];
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						ans=max(ans,x[1][i]+x[2][j]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>x[i][1]>>x[i][2]>>x[i][3];
				mx=max(x[i][1],max(x[i][2],x[i][3]));
				ans+=mx;
				if(mx==x[i][1]){
					l[1]++;
					d[l[1]][1].f=i;
					d[l[1]][1].a=mx;
				}
				else if(mx==x[i][2]){
					l[2]++;
					d[l[2]][2].f=i;
					d[l[2]][2].a=mx;
				}
				else{
					l[3]++;
					d[l[3]][3].f=i;
					d[l[3]][3].a=mx;
				}
			}
			if(l[1]>lim){
				for(int i=1;i<=l[1];i++){
					for(int j=i+1;j<=l[1];j++){
						if(d[i][1].a<d[j][1].a)swap(d[i],d[j]);
					}
				}
				while(l[1]-lim>0){
					ans-=d[l[1]][1].a;
					mx=max(x[d[l[1]][1].f][2],x[d[l[1]][1].f][3]);
					ans+=mx;
					if(l[1]-lim==1){
						
					}
					if(mx==x[d[l[1]][1].f][2]){
						l[2]++;
						d[l[2]][2].f=d[l[1]][1].f;
						d[l[2]][2].a=mx;
					}
					else{
						l[3]++;
						d[l[3]][3].f=d[l[1]][1].f;
						d[l[3]][3].a=mx;
					}
					l[1]--;
				}
			}
			if(l[2]>lim){
				for(int i=1;i<=l[2];i++){
					for(int j=i+1;j<=l[2];j++){
						if(d[i][2].a<d[j][2].a)swap(d[i],d[j]);
					}
				}
				while(l[2]-lim>0){
					ans-=d[l[2]][2].a;
					ans+=x[d[l[2]][2].f][3];
					l[2]--;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
