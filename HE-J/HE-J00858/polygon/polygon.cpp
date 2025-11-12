#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],s,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			if(sum>(a[j]*2)&&(j-i+1>=3))s++;
		}
	}
	cout<<s%998244353;
	return 0;
}
