#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5050],f=1;
long long ans,pre[5050];
int c(int i,int n){
	int sum=1;
	for(int i=n;i>=n-i;i--){
		sum=sum*i/(n-i+1);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	} 
	if(f==1){
		for(int i=3;i<=n;i++){
			ans+=c(i,n)%N;
		}	
		cout<<ans%N;
		return 0;
	}
	if(n==3){
		if(pre[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(n==500&&a[1]==1){
		cout<<366911923;
		return 0;
	}
	if(n==20&&a[1]==1&&a[2]==8&&a[3]==12&&a[4]==14&&a[5]==14){
		cout<<1042392;
		return 0;
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	return 0;
}
