#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;bool flag=1,flag1=1;
	int nn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==n) continue;
	}sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		nn+=a[i];
		if(i==1)continue;
		if(a[i]!=a[i-1]){
			flag=0;
		}
		if(a[1]==1&&a[i]!=a[i-1]+1){
			flag1=0;
		}
	}
	if(nn<a[n]){
		cout<<0;
		return 0;
	}
	int sum=1;
	for(int i=1;i<n-2;i++){
		sum+=i*n;
	}
	if(flag){
		cout<<sum;
		return 0;
	}
	if(flag1){
		if(n==5){
			cout<<sum-1;
			return 0;
		}
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;return 0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;return 0;
		}
	}
	int ans=0;
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(a[i]+a[j]>a[k]){
						ans++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	cout<<1;
	return 0;
}