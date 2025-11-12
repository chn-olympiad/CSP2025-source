#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long t,n,rx,ry,rz,ans;
long long gx[N],gy[N],gz[N];
struct node{
	long long x,y,z;
	long long max1=-1,max2=-1,max3=-1;
};
node a[N];
bool cmp(long long p,long long q){
	return p>q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n;
		
		if(n==2){
			for (int i=1;i<=n;i++){
				cin >>a[i].x >>a[i].y >>a[i].z;
				a[i].max1=max(a[i].x,max(a[i].y,a[i].z));
				a[i].max3=min(a[i].x,min(a[i].y,a[i].z));
				if((a[i].max1==a[i].x && a[i].max3==a[i].y) || (a[i].max3==a[i].x && a[i].max1==a[i].y)) a[i].max2=a[i].z;
				else if((a[i].max1==a[i].z && a[i].max3==a[i].y) || (a[i].max3==a[i].z && a[i].max1==a[i].y)) a[i].max2=a[i].x;
				else a[i].max2=a[i].y;
			}
			if(a[1].max1==a[1].x) rx++;
			else if(a[1].max1==a[1].y) ry++;
			else rz++;
			if(a[2].max1==a[2].x) rx++;
			else if(a[2].max1==a[2].y) ry++;
			else rz++;
			if(rx>=n/2 || ry>=n/2 || rz>=n/2){
				if(a[1].max1-a[1].max2<a[2].max1-a[2].max2){
					long long t=0;
					a[1].max2=t;
					a[1].max2=a[1].max1;
					a[1].max1=t;
				}
				else if(a[1].max1-a[1].max2>a[2].max1-a[2].max2){
					long long t=0;
					a[2].max2=t;
					a[2].max2=a[2].max1;
					a[2].max1=t;
				}
			}
			ans+=a[1].max1+a[2].max1;
			cout <<ans <<endl;
			cout <<a[1].max1 <<endl <<a[2].max1;
		}
		else {
			for (int i=1;i<=n;i++){
				cin >>gx[i] >>gy[i] >>gz[i];
			}
			sort(gx+1,gx+1+n,cmp);
			sort(gy+1,gy+1+n,cmp);
			sort(gz+1,gz+1+n,cmp);
			for (int i=1;i<=n/2;i++){
				if(gy[1]==0 && gz[1]==0) ans+=gx[i];
				if(gx[1]==0 && gz[1]==0) ans+=gy[i];
				else ans+=gz[i];
			}
			cout <<ans;
		}
	}
	return 0;
}
