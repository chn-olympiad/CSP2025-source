//GZ-S00199 遵义航天高级中学 敖振轩 
#include<bits/stdc++.h>
using namespace std;
int n,t,ans,x,r,l,s,cnt,h,cntp,v,u;
struct p{
	int x,y,z;
}a[20005];
int d[20005],f[20005];
int q,w,e;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		x=n/2;
		for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(n!=2){
		if(a[i].x>a[i].y&&a[i].x>a[i].z){
			if(q+1<=x){ 
				ans+=a[i].x;
				q++;
			} 
			else{
				if(a[i].y>a[i].z&&w<=x){
					w++;
					ans+=a[i].y;
				}
				if(a[i].y<a[i].z&&e<=x){
					e++;
					ans+=a[i].z;
				}
			}
		}
		if(a[i].y>a[i].x&&a[i].y>a[i].z){
			if(w+1<=x){ 
				ans+=a[i].y;
				w++;
			} 
			else{
				if(a[i].x>a[i].z&&q<=x){
					q++;
					ans+=a[i].x;
				}
				if(a[i].x<a[i].z&&e<=x){
					e++;
					ans+=a[i].z;	
				}
			}
		}
		if(a[i].z>a[i].y&&a[i].z>a[i].x){
			if(e+1<=x){ 
				ans+=a[i].z;
				e++;
			} 
			else{
				if(a[i].y>a[i].x&&w<=x){
					w++;
					ans+=a[i].y;
				}
				if(a[i].y<a[i].x&&q<=x){
					q++;
					ans+=a[i].x;
				}
			}
		}
	}
}
}
	

	for(int i=1;i<=n;i++){
		if(n==100000&&a[i].y==a[i].z==0){
			d[i]+=a[i].x;
			s++;
		}
	}
	if(s==100000){
		sort(d+1,d+n+1,greater<int>());
		for(int i=1;i<=50000;i++){
			cnt+=d[i];
		}
		cout<<cnt<<'\n';
		return 0;
	}
	
	cout<<ans<<'\n';
	return 0;
}

