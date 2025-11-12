#include<bits/stdc++.h>
using namespace std;
int N=998244353;
int n,a[10001],sum=0,num=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-2;i++){
		int maxx=INT_MIN;
		num=0;
		for(int j=i;j<=n;j++){	
			if(a[j]>maxx)maxx=a[j];
			num+=a[j];
			if(j>i+2&&maxx*2<num){
				sum=(sum+1)%N;
			}
		}
	}
	cout<<sum*n;
}
