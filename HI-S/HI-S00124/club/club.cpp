#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	int n,a[100005][3];
	long long ans[4];
	for(int j=0;j<=3;j++) ans[j]=0;
	cin>>n;
	for(int j=1;j<=n;j++){
	for(int l=1;l<=3;l++){
		cin>>a[j][l];
	}
	if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]){
	ans[1]++;
	ans[0]+=a[j][1];
	}
	else if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3]){
	ans[2]++;
	ans[0]+=a[j][2];
	}
	else if(a[j][3]>=a[j][1]&&a[j][3]>=a[j][2]){
	ans[3]++;
	ans[0]+=a[j][3];
	}
	}	
	if(ans[1]<=n/2&&ans[2]<=n/2&&ans[3]<=n/2){
		cout<<ans[0]<<endl;
	}
	else{
		int c[100005],b=1;
		if(ans[1]>n/2){
		for(int j=1;j<=n;j++){
			if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]){
				c[b]=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);
				b++;
			}
		}
		sort(c+1,c+b);
		for(int j=1;j<=ans[1]-n/2;j++) ans[0]-=c[j];
		cout<<ans[0]<<endl;	
		}
		else if(ans[2]>n/2){
		for(int j=1;j<=n;j++){
			if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3]){
				c[b]=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
				b++;
			}
		}
		sort(c+1,c+b);
		for(int j=1;j<=ans[2]-n/2;j++) ans[0]-=c[j];
		cout<<ans[0]<<endl;	
		}
		if(ans[3]>n/2){
		for(int j=1;j<=n;j++){
			if(a[j][3]>=a[j][1]&&a[j][3]>=a[j][2]){
				c[b]=min(a[j][3]-a[j][1],a[j][3]-a[j][2]);
				b++;
			}
		}
		sort(c+1,c+b);
		for(int j=1;j<=ans[3]-n/2;j++) ans[0]-=c[j];
		cout<<ans[0]<<endl;	
		}
	}
	}
	return 0;
}

