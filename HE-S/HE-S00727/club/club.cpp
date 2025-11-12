#include<bits/stdc++.h>
using namespace std;
struct M{
	int x;
	int y;
	int z;
};
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	int t,n,sum=0;
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n;
		sum=0;
		int flag[n]={0},ren=n,maxn[n],aa,bb,cc;
		M a[n];
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				maxn[i]=1;
				sum+=a[i].x;
				aa++;
			}
			if(a[i].x<a[i].y&&a[i].y>a[i].z){
				maxn[i]=2;
				sum+=a[i].y;
				bb++;
			}
			else{
				maxn[i]=3;
				sum+=a[i].z;
				cc++;
			}
		}
		while(aa>n/2){
			int minn=100000,mi;
			for(int i=0;i<n;i++){
				if(maxn[i]==1){
					if(a[i].x<minn){
						mi=i;
						minn=a[i].x;
					}
				}
			}
			sum-=a[mi].x;
			if(a[mi].y>a[mi].z){
				maxn[mi]=2;
				bb++;
			}
			else{
				maxn[mi]=3;
				cc++;
			}
		}
		while(bb>n/2){
			int minn=100000,mi;
			for(int i=0;i<n;i++){
				if(maxn[i]==1){
					if(a[i].y<minn){
						mi=i;
						minn=a[i].y;
					}
				}
			}
			sum-=a[mi].y;
			if(a[mi].x>a[mi].z&&aa<n/2){
				sum+=a[mi].x;
			}
			else{
				sum+=a[mi].z;
			}
		}
		while(cc>n/2){
			int minn=100000,mi;
			for(int i=0;i<n;i++){
				if(maxn[i]==1){
					if(a[i].z<minn){
						mi=i;
						minn=a[i].z;
					}
				}
			}
			sum-=a[mi].z;
			if(a[mi].x>a[mi].z&&aa<n/2){
				sum+=a[mi].x;
			}
			else{
				sum+=a[mi].z;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
