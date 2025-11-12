#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	bool vis=true;
	long long ans=0;
	long long sum=0;
	long long mod=998244353;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			vis=false;
		}
	}
	if(vis==true&&n>=3){
		cout<<(n*n+2-3*n)/2;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==2||n==1){
		cout<<0;
		return 0; 
	}
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		sum+=i-2;
	}
	cout<<sum;
	return 0;
}