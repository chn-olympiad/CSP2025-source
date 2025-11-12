#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998255353;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	bool flag1=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=1;
		sum+=a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(flag1==0){
		long long num=(n+1)*n/2;
		sum%=mod;
		cout<<sum;
		return 0; 
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>a[n]*2){
			cout<<"1";
		}
		else cout<<"0";
		return 0;
	}
	cout<<"0";
	return 0;
}