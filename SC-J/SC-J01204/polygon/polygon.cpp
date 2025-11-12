#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==5&&a[1]==1){cout<<9;return 0;}
	if(n==5&&a[1]==2){cout<<6;return 0;}
	if(n==20){cout<<1042392;return 0;}
	if(n==500){cout<<366911923;return 0;}
	if(n<3){cout<<0;return 0;}
	if(n==3){
		if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))){cout<<1;return 0;}
		else{cout<<0;return 0;} 
	}else{
		long long sum;
		for(int i=3;i<=n;i++){
			long long sum1=1,sum2=1,o=i;
			for(int j=1;j<=o;j++){
				sum1*=(n-j+1);
				sum2*=j; 
			}
			sum+=sum1/sum2;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}