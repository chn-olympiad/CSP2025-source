#include <bits/stdc++.h>
using namespace std;
long long t,n,ans=0,f,a[13],g;
struct s{
	long long a,b,c,maxx,maxb,emax;
}d[100010];
bool cmp(s x,s y){
	return (x.maxx-x.emax)>(y.maxx-y.emax);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		f=n/2;
		a[1]=a[2]=a[3]=0;
		for(int j=1;j<=n;j++){
			cin>>d[j].a>>d[j].b>>d[j].c;
			d[j].maxx=max(d[j].a,max(d[j].b,d[j].c));
			if(d[j].maxx==d[j].a){
				d[j].maxb=1;
				d[j].emax=max(d[j].b,d[j].c);
			}
			else if(d[j].maxx==d[j].b){
				d[j].maxb=2;
				d[j].emax=max(d[j].a,d[j].c);
			}
			else{
				d[j].maxb=3;
				d[j].emax=max(d[j].a,d[j].b);
			} 
			
		}
		sort(d+1,d+1+n,cmp);
//		for(int j=1;j<=n;j++){
//			cout<<d[j].maxx<<" "<<d[j].emax<<endl;
//		}
		for(int j=1;j<=n;j++){
			if(a[d[j].maxb]<f){
				a[d[j].maxb]++;
				ans+=d[j].maxx;
			}
			else{
				ans+=d[j].emax;
			}
			
		}
		
		cout<<ans<<endl;
	}
} 
