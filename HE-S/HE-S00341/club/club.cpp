#include<bits/stdc++.h>
using namespace std;
int t,n,maxj[4],ans,mum2[10^5+1];
bool isover(int j){
	if(maxj[j]<n/2){
		return 0;
	}else{
		return 1;
	}
}
int noover(int q,int i){
	mum2[i]=max(q,mum2[i]);
	return mum2[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a[n+1][4];
		int temp[n+1]={};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		
		int max1[n+1],max2[n+1],max3[n+1];	
		bool isdone=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){	
	 				max1[i]=noover(a[i][j],i);	
			}
		}
		for(int i=1;i<=n;i++) ans+=max1[i];
		cout<<ans<<endl;
		ans=0;
		maxj[1]=0;maxj[2]=0;maxj[3]=0;
		for(int i=1;i<=n;i++) max1[i]=0;
	}
	return 0;
}
