#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,ma,zh,zma,zzh;
}a[100010];
int n,b[10],ans,t;
bool cmp(node u,node v){
	return u.ma>v.ma;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
for(int p=1;p<=t;p++){
	ans=0;
	cin>>n;
	b[1]=b[2]=b[3]=n/2;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].y>=a[i].z){a[i].ma=a[i].x-a[i].z,a[i].zma=1,a[i].zh=a[i].y-a[i].z,a[i].zzh=2;}
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].z>=a[i].y){a[i].ma=a[i].x-a[i].y,a[i].zma=1,a[i].zh=a[i].z-a[i].y,a[i].zzh=3;}
		if(a[i].y>=a[i].x&&a[i].x>=a[i].z&&a[i].y>=a[i].z){a[i].ma=a[i].y-a[i].z,a[i].zma=2,a[i].zh=a[i].x-a[i].z,a[i].zzh=1;}
		if(a[i].y>=a[i].x&&a[i].z>=a[i].x&&a[i].y>=a[i].z){a[i].ma=a[i].y-a[i].x,a[i].zma=2,a[i].zh=a[i].z-a[i].x,a[i].zzh=3;}
		if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&a[i].x>=a[i].y){a[i].ma=a[i].z-a[i].y,a[i].zma=3,a[i].zh=a[i].x-a[i].y,a[i].zzh=1;}
		if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&a[i].y>=a[i].x){a[i].ma=a[i].z-a[i].x,a[i].zma=3,a[i].zh=a[i].y-a[i].x,a[i].zzh=2;}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].zma==1)ans+=a[i].x;
		if(a[i].zma==2)ans+=a[i].y;
		if(a[i].zma==3)ans+=a[i].z;
		b[a[i].zma]--;
		if(!b[a[i].zma]){
			for(int j=i+1;j<=n;j++){
				if(a[i].zma==a[j].zma){
					swap(a[j].zma,a[j].zzh);swap(a[j].ma,a[j].zh);
				}
			}
		}
	}
	cout<<ans<<endl;
}
}
