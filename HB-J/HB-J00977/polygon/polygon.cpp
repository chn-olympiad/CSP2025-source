#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long sum=1;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			long long sum1=1;
			for(int k=1;k<=i*j;k++){
				 sum1*=k;
			 }
			 sum+=sum1;
			 }
			 }
			 cout<<sum;
	return 0;
	}
