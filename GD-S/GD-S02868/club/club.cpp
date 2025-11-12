#include<bits/stdc++.h>
using namespace std;
struct st{
	bool c;
	long long a1,a2,a3;
	long long d1,d2,d3;
	long long d1p,d2p,d3p;
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0,n=0,sum=0;
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>n;
		long long g1[n+1],g2[n+1],g3[n+1];
		for(long long j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			a[j].c=false;
			if(a[j].a1<a[j].a2&&a[j].a1<a[j].a3&&a[j].a2<a[j].a3){
				a[j].d1=a[j].a3;
				a[j].d1p=3;
				a[j].d2=a[j].a2;
				a[j].d2p=2;
				a[j].d3=a[j].a1;
				a[j].d3p=1;
			}
			else if(a[j].a1<a[j].a2&&a[j].a1>a[j].a3&&a[j].a2>a[j].a3){
				a[j].d1=a[j].a2;
				a[j].d1p=2;
				a[j].d2=a[j].a1;
				a[j].d2p=1;
				a[j].d3=a[j].a3;
				a[j].d3p=3;
			}
			else if(a[j].a1>a[j].a2&&a[j].a1>a[j].a3&&a[j].a2>a[j].a3){
				a[j].d1=a[j].a1;
				a[j].d1p=1;
				a[j].d2=a[j].a2;
				a[j].d2p=2;
				a[j].d3=a[j].a3;
				a[j].d3p=3;
			}
			else if(a[j].a1>a[j].a2&&a[j].a1<a[j].a3&&a[j].a2<a[j].a3){
				a[j].d1=a[j].a3;
				a[j].d1p=3;
				a[j].d2=a[j].a1;
				a[j].d2p=1;
				a[j].d3=a[j].a2;
				a[j].d3p=2;
			}
			else if(a[j].a1>a[j].a2&&a[j].a1>a[j].a3&&a[j].a2<a[j].a3){
				a[j].d1=a[j].a1;
				a[j].d1p=1;
				a[j].d2=a[j].a3;
				a[j].d2p=3;
				a[j].d3=a[j].a2;
				a[j].d3p=2;
			}
			else if(a[j].a1<a[j].a2&&a[j].a1<a[j].a3&&a[j].a2>a[j].a3){
				a[j].d1=a[j].a2;
				a[j].d1p=2;
				a[j].d2=a[j].a3;
				a[j].d2p=3;
				a[j].d3=a[j].a1;
				a[j].d3p=1;
			}
		}
		sum=0;
		for(long long j=1;j<=3;j++){
			long long c=LONG_LONG_MIN,c1=0,c2,c3;
			for(long long k=1;k<=n;k++){
				if(a[k].d1p==1&&a[k].d1>c&&a[k].c!=1){
					c1=c;
					c3=c2;
					c=a[k].d1;
					c2=k;
				}
				
			}
			sum+=c+c1;
			a[c2].c=true;
			a[c3].c=true;
			c=LONG_LONG_MIN,c1=0,c2,c3;
			for(long long k=1;k<=n;k++){
				if(a[k].d1p==2&&a[k].d1>c&&a[k].c!=1){
					c1=c;
					c3=c2;
					c=a[k].d1;
					c2=k;
				}
			}
			sum+=c+c1;
			a[c2].c=true;
			a[c3].c=true;
			c=LONG_LONG_MIN,c1=0,c2,c3;
			for(long long k=1;k<=n;k++){
				if(a[k].d1p==3&&a[k].d1>c&&a[k].c!=1){
					c1=c;
					c3=c2;
					c=a[k].d1;
					c2=k;
				}
			}
			sum+=c+c1;
			a[c2].c=true;
			a[c3].c=true;
		}
		cout<<sum<<"\n";
		sum=0;
	}
	return 0;
}
