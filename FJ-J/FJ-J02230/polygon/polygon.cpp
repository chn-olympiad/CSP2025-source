#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int sum;
		for(int j=1;j<i;j++){
			sum+=a[j];
		}
		for(int l=1;l<=n-i+1;l++){
			for(int j=l;j<=n-i+1;j++){
				if(sum>a[i+j-1])++ans;
				sum+=a[i+j-1]-a[j+1];
			}	
		}
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
