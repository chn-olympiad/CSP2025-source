#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum=0,numm=1;
int main(){
	freopen("polygon.in1","r",stdin);
	freopen("polygon.out1","w",stdout);
	freopen("polygon.in2","r",stdin);
	freopen("polygon.out2","w",stdout);
	freopen("polygon.in3","r",stdin);
	freopen("polygon.out3","w",stdout);
	freopen("polygon.in4","r",stdin);
	freopen("polygon.out4","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>=a[3]*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=n;i>=3;i--){
		int num=0;
		for(int j=n-1;j>=1;j--){
			numm++;
			num=num+a[j];
			if(numm>=3){
				if(num+a[i]>a[i]*2){
				    sum=sum+j;
				    break;
			    }
			}
		}
	}
	cout<<sum;
    return 0;
}
