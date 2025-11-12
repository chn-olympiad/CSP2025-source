#include<bits/stdc++.h>
using namespace std;
int a[5555];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,ma;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		ma=max(max(a[i],a[i+1]),a[i+2]);
		if(a[i]+a[i+1]+a[i+2]>ma*2)sum++;
	}
	cout<<sum;
	return 0;
}
