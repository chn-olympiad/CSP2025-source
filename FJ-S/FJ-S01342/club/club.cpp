#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,maxn;
struct No{
	int name,pf;
}a[N],b[N],c[N],x[N],y[N],z[N];
bool cmp(No x,No y){
	if((a[x.name].pf==0&&b[x.name].pf==0)||(a[x.name].pf==0&&c[x.name].pf==0)||(b[x.name].pf==0&&c[x.name].pf==0))return 1;
	else if((a[y.name].pf==0&&b[y.name].pf==0)||(a[y.name].pf==0&&c[y.name].pf==0)||(b[y.name].pf==0&&c[y.name].pf==0))return 0;
	else return x.pf>y.pf;
}
int main (){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].pf>>b[i].pf>>c[i].pf;
			maxn=max(a[i].pf,max(b[i].pf,c[i].pf));
			if(maxn==a[i].pf){
				x[++l1].name=i;
				x[l1].pf=a[i].pf;
			}
			else if(maxn==b[i].pf){
				y[++l2].name=i;
				y[l2].pf=b[i].pf;
			}
			else {
				z[++l3].name=i;
				z[l3].pf=c[i].pf;
			}
			a[i].name=b[i].name=c[i].name=i;
		}
		sort(x+1,x+l1+1,cmp);
		sort(y+1,y+l2+1,cmp);
		sort(z+1,z+l3+1,cmp);
		if(l1>n/2){
			int u=l1;
			l1=n/2;
			for(int i=n/2+1;i<=u;i++){
				maxn=max(b[x[i].name].pf,c[x[i].name].pf);
				if(maxn==b[x[i].name].pf&&l2+1<=n/2){
					y[++l2].name=i;
					y[l2].pf=b[x[i].name].pf;
				}
				else {
					z[++l3].name=i;
					z[l3].pf=c[x[i].name].pf;
				}
			}
		}
		else if(l2>n/2){
			int u=l2;
			l2=n/2;
			for(int i=n/2+1;i<=u;i++){	
				maxn=max(a[y[i].name].pf,c[y[i].name].pf);
				if(maxn==a[y[i].name].pf&&l1+1<=n/2){
					x[++l1].name=i;
					x[l1].pf=a[y[i].name].pf;
				}
				else {
					z[++l3].name=i;
					z[l3].pf=c[y[i].name].pf;
				}		
			}
		}
		else if(l3>n/2){
			int u=l3;
			l3=n/2;
			for(int i=n/2+1;i<=l3;i++){
				maxn=max(a[z[i].name].pf,b[z[i].name].pf);
				if(maxn==b[z[i].name].pf&&l2+1<=n/2){
					y[++l2].name=i;
					y[l2].pf=b[z[i].name].pf;
				}
				else {
					x[++l1].name=i;
					x[l1].pf=a[z[i].name].pf;
				}		
			}
		}
		int mm=0;
		for(int i=1;i<=l1;i++){
			mm+=x[i].pf;
		}
		for(int i=1;i<=l2;i++){
			mm+=y[i].pf;
		}
		for(int i=1;i<=l3;i++){
			mm+=z[i].pf;
		}
		cout<<mm<<"\n";	
	}
	return 0;
}