#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i;k<=j;k++){
				sort(a+i+1,a+j+1,greater<long long>());
				if(sum>a[k]*2) cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
