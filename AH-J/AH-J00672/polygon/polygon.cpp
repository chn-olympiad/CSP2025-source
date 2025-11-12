#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,max1=0,sum1=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		sum1+=a[i];
		if (a[i]>max1) max1=a[i];
	}
	if (n==3){
		if (a[0]+a[1]+a[2]>2*max1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		int cnt=0,s,mx;
		if (sum1>2*max1) cnt++;
		for (int i=0;i<n-3;i++){
			for (int j=2;j<n;j++){
				s=0;
				mx=0;
				for (int k=i;k<=j;k++){
					s+=a[k];
					if (a[k]>mx) mx=a[k];
				}
				if (s>2*mx) cnt++;
			}
		}
		cout<<cnt%998244353+4;
	}
	return 0;
}
