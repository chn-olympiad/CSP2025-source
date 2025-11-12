#include<bits/stdc++.h>
using namespace std;
long long n,k,a[555555],ma=INT_MIN;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long x=0,y=0;
		for(int j=1;j<=i;j++){
			x=a[j-1]^a[j];
		}
		for(int j=i+1;j<=n;j++){
			y=a[j-1]^a[j];
		}
		if(x==y&&y==k){
			if(x>ma){
				ma=x;
			}
		}
	}
	cout<<ma;
	return 0;
}
