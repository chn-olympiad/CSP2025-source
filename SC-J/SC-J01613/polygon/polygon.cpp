#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,sum=0,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		if(a[i]>mx)mx=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=0;
			sum+=a[i]+a[j];
			if(sum>=mx*2)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
