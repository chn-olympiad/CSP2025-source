#include<bits/stdc++.h>
using namespace std;
struct Members{
	int x,y,z;
	int deltaxy,deltayz,deltaxz;
	int max;
	bool cx,cy,cz;
}a[100001];
int n;
int sumx,sumy,sumz;
int t;
long long int ans[6];
long long int w[1000001];
long long int k[1000001];
long long int l[1000001];
void compete(int i){
	if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
		a[i].max=a[i].x;
		sumx++;
		a[i].cx=1;
		}
	if(a[i].y>a[i].x&&a[i].y>a[i].z){
		a[i].max=a[i].y;
		sumy++;
		a[i].cy=1;
		}
	if(a[i].z>a[i].x&&a[i].z>a[i].y){
		a[i].max=a[i].z;
		sumz++;
		a[i].cz=1;
		}
	if(a[i].x>=a[i].y)a[i].deltaxy=a[i].x-a[i].y;
	else a[i].deltaxy=a[i].y-a[i].x;
	if(a[i].y>=a[i].z)a[i].deltayz=a[i].y-a[i].z;
	else a[i].deltayz=a[i].z-a[i].y;
	if(a[i].x>=a[i].z)a[i].deltaxz=a[i].x-a[i].z;
	else a[i].deltaxz=a[i].z-a[i].x;
}
int min(int x,int y){
	if(x<=y)return x;
	else return y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		sumx=0;
		sumy=0;
		sumz=0;
		for(int i=1;i<=n;i++){
			w[i]=0;
			k[i]=0;
			l[i]=0;
			a[i].cx=0;
			a[i].cy=0;
			a[i].cz=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			compete(i);
			ans[o]+=a[i].max;
//			cout<<ans[o]<<endl;
		}
//		cout<<sumy<<endl;
		if(sumx<=n/2&&sumy<=n/2&&sumz<=n/2)continue;
		else {
				if(sumx>n/2){
					int j=1;
					for(int i=1;i<=n;i++){
						if(a[i].cx){
							w[j]=min(a[i].deltaxy,a[i].deltaxz);
							j++;
						}
					}
					sort(w+1,w+j);
					int e=1;
					while(sumx>n/2){
						ans[o]-=w[e];
						e++;
						sumx--;
					}
				}
				if(sumy>n/2){
					int j=1;
					for(int i=1;i<=n;i++){
						if(a[i].cy){
							k[j]=min(a[i].deltaxy,a[i].deltayz);
							j++;
						}
					}
					sort(k+1,k+j);
					int e=1;
					while(sumy>n/2){
						ans[o]-=k[e];
						e++;
						sumy--;
					}
				}
				if(sumz>n/2){
					int j=1;
					for(int i=1;i<=n;i++){
						if(a[i].cz){
							l[j]=min(a[i].deltayz,a[i].deltaxz);
							j++;
						}
					}
					sort(l+1,l+j);
					int e=1;
					while(sumz>n/2){
						ans[o]-=l[e];
						e++;
						sumz--;
					}
				}
			 }
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}
