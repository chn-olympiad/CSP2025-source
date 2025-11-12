#include "bits/stdc++.h"
using namespace std;
long long a[100010][4],ma,ans,n,maxx;
void qc(int b,int k,int l,int r){
	while(b>n/2){
			int maxx=0,x=0,i,y,m,m1=INT_MAX;
			for(i=n;i>=0;i--){
				if(a[i][0]==k){
					ma=max(a[i][l],a[i][r]);
					m=a[i][k]-ma;
					if(ma==a[i][l])y=l;
					if(ma==a[i][r])y=r;
				    if(m<m1){
				    	maxx=ma;
				    	m1=m;
				    	x=i;
					}
				}
			}
			b--;
			ans=ans-a[x][k]+maxx;
			a[x][0]=y;
			a[x][k]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,b,c,d;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		b=0;
		c=0;
		d=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(ma==a[i][1]){
				a[i][0]=1;
				b++;
			}
			else if(ma==a[i][2]){
				a[i][0]=2;
				c++;
			}
			else if(ma==a[i][3]){
				a[i][0]=3;
				d++;
			}
			ans+=ma;
		}
		if(b>n/2)qc(b,1,2,3);
		if(c>n/2)qc(c,2,1,3);
		if(d>n/2)qc(d,3,1,2);
		cout<<ans<<endl;
		for(i=1;i<=n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
	}
	return 0;
} 
