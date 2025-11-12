#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,s=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,max_=0,max2_=0,max3_=0,maxn=0,cnt=0;
		cin>>n;
		if(n==2){
			for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j]; 
			}
			cout<<max(a[1]+b[2],max(a[1]+b[3],max(a[2]+b[1],max(a[2]+b[3],max(a[3]+b[1],a[3]+b[2])))))<<endl;
		}
		else {
			for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j];		
			}	
			for(int j=1;j<=n;j++){
				max_=max(max_,a[j]);
				max2_=max(max2_,b[j]);
				max3_=max(max3_,c[j]);
			}
			int max1=0,max2=0,max3=0;
			for(int j=1;j<=n;j++){
				if(max_==a[j]) a[j]=0,b[j]=0,c[j]=0,max1=max_,max_=-1;
				else if(max2_==b[j]) b[j]=0,a[j]=0,b[j]=0,max2=max2_,max2_=-1;
				else if(max3_==c[j]) c[j]=0,a[j]=0,b[j]=0,max3=max3_,max3_=-1;
			}
			for(int j=1;j<=n;j++){
				maxn=max(maxn,max(a[j],max(b[j],c[j])));					
			}
			cout<<max1+max2+max3+maxn<<endl;
			}
	}
	return 0;
} 
