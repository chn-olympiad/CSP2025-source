#include<bits/stdc++.h>
using namespace std;
long long a[5100],n,ans,sum=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=4;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			sum=sum*(n-j);
		}
		for(int j=0;j<=i-1;j++){
			sum=sum/(i-j);
		}
		ans+=sum;
		sum=1;
	}
	cout<<ans;
	return 0;
} 
