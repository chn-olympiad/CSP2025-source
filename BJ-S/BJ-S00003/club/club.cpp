#include<bits/stdc++.h>
using namespace std;
struct datanode{
	long long x,y,z;
};
struct node{
	long long w;
	char t;
	long long p;
};
bool cmp(node x,node y){
	return x.w>y.w;
}
void init(){
	long long n,ans=0;
	node a[300009];
	datanode mcws[100009];
	bool b[100009];
	cin>>n;
	for(long long i=1;i<=n;i++){
		b[i]=1;
	}
	for(long long i=1;i<=n*3;i+=3){
		long long x,y,z;
		cin>>x>>y>>z;
		a[i  ]={x-(y+z)/2,1,i/3+1};
		a[i+1]={y-(x+z)/2,2,i/3+1};
		a[i+2]={z-(x+y)/2,3,i/3+1};
		mcws[i/3+1]={x,y,z};
	}
	sort(a+1,a+(n*3)+1,cmp);
	long long x=0,y=0,z=0;
	for(long long i=1;i<=n*3;i++){
		//cout<<a[i].p<<endl;
		if(a[i].t==1&&x<n/2&&b[a[i].p]){
			b[a[i].p]=0;
			ans+=mcws[a[i].p].x;
			x++;
			//cout<<a[i].p<<"a"<<endl;
		}
		else if(a[i].t==2&&y<n/2&&b[a[i].p]){
			b[a[i].p]=0;
			ans+=mcws[a[i].p].y;
			y++;
			//cout<<a[i].p<<"b"<<endl;
		}
		else if(a[i].t==3&&z<n/2&&b[a[i].p]){
			b[a[i].p]=0;
			ans+=mcws[a[i].p].z;
			z++;
			//cout<<a[i].p<<"c"<<endl;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=1;i<=t;i++){
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
