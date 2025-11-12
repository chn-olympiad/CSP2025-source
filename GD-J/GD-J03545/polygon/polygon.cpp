#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	int sum=0,num=1,k=1;
	for(int i=3;i<=n;i++){
		sum+=num;
		num=sum;
		num+=k*3;
		k++;
		sum%=998244353;
		num%=998244353;
	}
	cout<<sum;
	return 0;
} 
