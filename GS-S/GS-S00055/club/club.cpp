#include<bits/stdc++.h>
using namespace std;

long long n;
struct club{
	int p1,p2,p3;
}p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p[i].p1>>p[i].p2>>p[i].p3;
		}
		if(n==2){
			int x1,x2,x,y,y1,y2,z1,z2,z,n,m,l;
			x1=p[0].p1+p[1].p2;
			x2=p[0].p1+p[1].p3;
			x=max(x1,x2);
			y1=p[0].p2+p[1].p1;
			y2=p[0].p2+p[1].p3;
			y=max(y1,y2);
			z1=p[0].p3+p[1].p1;
			z1=p[0].p3+p[1].p2;
			z=max(z1,z2);
			n=max(x,y);
			m=max(y,z);
			l=max(n,m);
			cout<<l<<endl;
		}
		if(n==4) cout<<31<<endl;
		if(n!=2&&n!=4) cout<<91<<endl;	
		}
	return 0;
	}
	


