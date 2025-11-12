#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[30],num[30],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	for(int i=3;i<=n;i++){
		int temp=0;
		for(int j=i;j<=n;j++){
			int t=1;
			for(int k=1;k<=i-1;k++) t*=j-k;
			temp+=t;
		}
		for(int j=i-1;j>1;j--) temp/=j;
		ans+=temp;
		ans%=998224353;
	}
	cout<<ans;
	return 0;
}