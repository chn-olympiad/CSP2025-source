#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct aa{
	int x,y,z,i;
}a[100010];
int t;
int n;

bool cmp(aa x,aa y){
	int ma1=max(x.x,x.y);
	int ma2=max(x.z,x.y);
	int ma3=max(x.x,x.z);
	int xx,yy;
	if(ma1==ma2)xx=ma1-ma3;
	else if(ma1==ma3)xx=ma1-ma2;
	else if(ma2==ma3)xx=ma2-ma1;
	int may1=max(y.x,y.y);
	int may2=max(y.z,y.y);
	int may3=max(y.x,y.z);
	if(may1==may2)yy=may1-may3;
	else if(may1==may3)yy=may1-may2;
	else if(may2==may3)yy=may2-may1;
	if(xx!=yy)return xx>yy;
	if(max(ma1,max(ma2,ma3))!=max(may1,max(may2,may3)))return max(ma1,max(ma2,ma3))>max(may1,max(may2,may3));
	if(min(ma1,min(ma2,ma3))!=min(may1,min(may2,may3)))return min(ma1,min(ma2,ma3))>min(may1,min(may2,may3));
	return min(x.x,min(x.y,x.z))>min(y.x,min(y.y,y.z));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;cin>>x>>y>>z;
			a[i].x=x;
			a[i].y=y;
			a[i].z=z;
			a[i].i=i;
		}
		sort(a+1,a+n+1,cmp);
		int s=0,ca=0,cb=0,cc=0,fb=0;
		for(int i=1;i<=n;i++){
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(x>y&&x>z&&ca<n/2){//均不相等 
				ca++;s+=x;
			}else if(y>x&&y>z&&cb<n/2){
				cb++;s+=y;
			}else if(z>x&&z>y&&cc<n/2){
				cc++;s+=z;
			}else if(x>z&&x>y&&y!=z){
				if(y>z){
					s+=y;cb++;
				}else{
					s+=z;cc++;
				}
			}else if(y>z&&y>x&&x!=z){
				if(x>z){
					s+=x;ca++;
				}else{
					s+=z;cc++;
				}
			}else if(z>x&&z>y&&x!=y){
				if(x>y){
					s+=x;ca++;
				}else{
					s+=y;cb++;
				}
			}else if(x==y&&x==z){//均相等 
				s+=x;
			}else if(x==y){//二相等一不等
				s+=x;
			}else if(x==z){
				s+=x;
			}else if(y==z){
				s+=y;
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
