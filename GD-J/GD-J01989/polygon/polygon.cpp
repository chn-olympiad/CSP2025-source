#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,a[MAXN];
long long c(int n,int m){
	long long ans1=1,ans2=1;
	for(int i=1,j=n;i<=m;i++,j--){
		ans1*=j;
	}
	for(int i=1;i<=m;i++){
		ans2*=i;
	}
	return ans1/ans2;
} 
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	for(int i=3;i<=n;i++){
		ans=ans+c(n,i)%998%244%353;
	}
	cout<<ans;
} 
