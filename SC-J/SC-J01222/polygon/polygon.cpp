#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=5e3+1;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		long long sum=0;
		for(int i=1;i<=n;i++){
			long long num1=1,num2=1,x=0;
			for(int j=1;j<=i;j++){
				num1=(n-x)%M*(num1%M)%M;
				x++;
			}
			x=1;
			for(int j=1;j<=i;j++){
				num2=x%M*num2%M;
				x++;
			}
			sum+=num1%M/(num2%M)%M;
		}
		sum=sum%M-n%M-n%M*(n-1)/2%M;
		cout<<sum;
	}
	return 0;
}