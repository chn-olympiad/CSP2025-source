#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) sum++;
			}	
		}	
	}
	cout<<sum%998244353;

	return 0;
}
