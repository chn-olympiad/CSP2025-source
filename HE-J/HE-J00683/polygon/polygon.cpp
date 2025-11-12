#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long sum;
unsigned long long num1=1,num2=1;
int a[10086];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(a[n]==1){
		for(int i=3;i<=n-2;i++){
			for(int j=1;j<=i;j++){
				num2*=j;
				num1*=n-j+1;
				//cout<<num1<<" "<<num2<<" ";
			}
			sum+=num1/num2;
			num1=1;num2=1;
		}
		cout<<sum+n+1;
		return 0;
	}
	return 0;
}
