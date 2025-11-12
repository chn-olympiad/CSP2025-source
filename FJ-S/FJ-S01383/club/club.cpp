#include<bits/stdc++.h>
using namespace std;
int t; 
struct f{
	int x,y,z,id;
};
bool cmp1(f a,f b){
	return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);
}
bool cmp2(f a,f b){
	return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);
}
bool cmp3(f a,f b){
	return a.z-max(a.x,a.y)<b.z-max(b.x,b.y);
}
      int main(){
      	freopen("club.in","r",stdin);
      	freopen("club.out","w",stdout);
        cin>>t;
		while(t--){
		long long n,num[4],ans=0,cnt=1;
		int flag=0;
		f a[100005];
		cin>>n;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				num[1]++;
				ans+=a[i].x;
				a[i].id=1;
			}
			if(a[i].y>a[i].x&&a[i].y>=a[i].z){
				num[2]++;
				ans+=a[i].y;
				a[i].id=2;
			}
			if(a[i].z>a[i].y&&a[i].z>a[i].x){
				num[3]++;
				ans+=a[i].z;
				a[i].id=3;
			}
		}
		if(num[1]>n/2){
	      flag=1;
	      sort(a+1,a+1+n,cmp1);
     	}
		if(num[2]>n/2){
			flag=2;
	      sort(a+1,a+1+n,cmp2);
		}
		if(num[3]>n/2){
			flag=3;
	      sort(a+1,a+1+n,cmp3);
		}
        if(flag){
		while(num[flag]>n/2){ 
		   if(flag==1&&a[cnt].id==1){
		   	ans=ans+max(a[cnt].y,a[cnt].z)-a[cnt].x;
		   	num[1]--;
		   }
		   if(flag==2&&a[cnt].id==2){
		   	ans=ans+max(a[cnt].x,a[cnt].z)-a[cnt].y;
		   	num[2]--;
		   }
		   if(flag==3&&a[cnt].id==3){
		   	ans=ans+max(a[cnt].y,a[cnt].x)-a[cnt].z;
		   	num[3]--;
		   }
		   cnt++;
		}
	}
	    cout<<ans<<endl;
	
		}
      	return 0;
	  } 
