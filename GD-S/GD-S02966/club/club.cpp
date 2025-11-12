#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans;
struct data{
	int x,y,z,maxn;
}a[100005];
bool cmp1(data k,data z){
	return k.x>z.x;
}
bool cmp2(data k,data z){
	return k.maxn>z.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0){
				f1=false;
			}
			if(a[i].z!=0){
				f2=false;
			}
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
		}
		if(f1==true&&f2==true){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(f2==true){
			sort(a+1,a+n+1,cmp2);
			int sum[2];
			memset(sum,0,sizeof sum);
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y){
					if(sum[0]<n/2){
						sum[0]++,ans+=a[i].x;
					}
					else{
						sum[1]++,ans+=a[i].y;
					}
				}
				else if(a[i].x==a[i].y){
					if(sum[0]>sum[1]){
						sum[1]++,ans+=a[i].y;
					}
					else{
						sum[0]++,ans+=a[i].x;
					}
				}
				else{
					if(sum[1]<n/2){
						sum[1]++,ans+=a[i].y;
					}
					else{
						sum[0]++,ans+=a[i].x;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp2);
		int sum[3];
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++){
			if(a[i].x==a[i].maxn){
				if(sum[0]<n/2){
					sum[0]++,ans+=a[i].x;
				}
				else if(a[i].y>a[i].z){
					sum[1]++,ans+=a[i].y;
				}
				else if(a[i].y==a[i].z){
					if(sum[1]<sum[2]){
						sum[1]++,ans+=a[i].y;
					}
					else{
						sum[2]++,ans+=a[i].z;
					}
				}
				else if(a[i].y<a[i].z){
					sum[2]++,ans+=a[i].z;
				}
			}
			else if(a[i].y==a[i].maxn){
				if(sum[1]<n/2){
					sum[1]++,ans+=a[i].y;
				}
				else if(a[i].x>a[i].z){
					sum[0]++,ans+=a[i].x;
				}
				else if(a[i].x==a[i].z){
					if(sum[0]<sum[2]){
						sum[0]++,ans+=a[i].x;
					}
					else{
						sum[2]++,ans+=a[i].z;
					}
				}
				else if(a[i].x<a[i].z){
					sum[2]++,ans+=a[i].z;
				}
			}
			else{
				if(sum[2]<n/2){
					sum[2]++,ans+=a[i].z;
				}
				else if(a[i].x>a[i].y){
					sum[0]++,ans+=a[i].x;
				}
				else if(a[i].x==a[i].y){
					if(sum[0]<sum[1]){
						sum[0]++,ans+=a[i].x;
					}
					else{
						sum[1]++,ans+=a[i].y;
					}
				}
				else if(a[i].x<a[i].y){
					sum[2]++,ans+=a[i].y;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
