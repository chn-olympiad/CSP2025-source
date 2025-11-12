#include<bits/stdc++.h>
using namespace std;
struct le{
	long long x,y,z;
	long long xy,xz,yz,yx,zx,zy;
};
le a[100100];
long long a1=0,a2=0,a3=0,n,sum=0,k;
long long cha[100010],chai=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		a1=0,a2=0,a3=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xy=a[i].x-a[i].y;
			a[i].xz=a[i].x-a[i].z;
			a[i].zy=a[i].z-a[i].y;
			a[i].yz=a[i].y-a[i].z;
			a[i].zx=a[i].z-a[i].x;
			a[i].yx=a[i].y-a[i].x;
			if(a[i].x>a[i].y and a[i].x>a[i].z)a1++;
			else if(a[i].y>a[i].z)a2++;
			else a3++;
			sum+=max(a[i].x,max(a[i].y,a[i].z));
		}
		chai=1;
		if(a1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y and a[i].x>a[i].z){
					cha[chai]=min(a[i].xy,a[i].xz);
					chai++;
				}
			}
			sort(cha+1,cha+chai);
			for(int i=1;i<=a1-(n/2);i++){
				sum-=cha[i];
			}
		}
		if(a2>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].y>a[i].x and a[i].y>a[i].z){
					cha[chai]=min(a[i].yx,a[i].yz);
					chai++;
				}
			}
			sort(cha+1,cha+chai);
			for(int i=1;i<=a2-(n/2);i++){
				sum-=cha[i];
			}
		}
		if(a3>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].z>a[i].y and a[i].z>a[i].x){
					cha[chai]=min(a[i].zy,a[i].zx);
					chai++;
				}
			}
			sort(cha+1,cha+chai);
			for(int i=1;i<=a3-(n/2);i++){
				sum-=cha[i];
			}
		}
		cout<<sum<<endl;
	}
}
