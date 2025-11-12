#include<bits/stdc++.h>
using namespace std;
long long t,n,sum=0,teshu=0;
long long a[100001][4],te[100001];
int maxinum[4];
long long maxn[100001];
long long minn[100001];
long long midn[100001];
long long cha[100001];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	for(int i=1;i<=t;i++){
		sum=0;
		cin>>n;
		teshu=0;
		for(int y=1;y<=n;y++){
			maxinum[y]=0;
			for(int j=1;j<=3;j++){
				cin>>a[y][j];
				if(a[y][j]==0 and j>1) {
					teshu+=1;
					}
				else{
					te[y]=a[y][1];}
				
			}
		}
		if(teshu==2*n){
			sort(te,te+n+1);
			for(int w=n;w>n/2;w--){
				sum+=te[w];}
			cout<<sum<<endl;
			break;}
		
		
		for(int j=1;j<=n;j++){
			maxn[j]=a[j][1]>a[j][2]?(a[j][1]>a[j][3]?a[j][1]:a[j][3]):(a[j][2]>a[j][3]?a[j][2]:a[j][3]);
			int maxi=a[j][1]>a[j][2]?(a[j][1]>a[j][3]?1:3):(a[j][2]>a[j][3]?2:3);
			maxinum[maxi]+=1;
			minn[j]=a[j][1]<a[j][2]?(a[j][1]<a[j][3]?a[j][1]:a[j][3]):(a[j][2]<a[j][3]?a[j][2]:a[j][3]);
			int mini=a[j][1]<a[j][2]?(a[j][1]<a[j][3]?1:3):(a[j][2]<a[j][3]?2:3);
			int midi=6-mini-maxi;
			midn[j]=a[j][midi];
			cha[j]=maxn[j]-midn[j];
		}
		for(int j=1;j<=n;j++){
			sum+=maxn[j];
			}
		if(maxinum[1]<=n/2 and maxinum[2]<=n/2 and maxinum[2]<=n/2){
			
			cout<<sum<<endl;}
		else{
			sort(cha,cha+n+1);
			int r=maxinum[1]>maxinum[2]?(maxinum[1]>maxinum[3]?maxinum[1]:maxinum[3]):(maxinum[2]>maxinum[3]?maxinum[2]:maxinum[3]);
			for(int w=1;w<=r-n/2;w++){
				sum-=cha[w];
				}
			cout<<sum<<endl;
			}
		
		}
	return 0;
}

