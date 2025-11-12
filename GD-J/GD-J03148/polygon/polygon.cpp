#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	vector<int> v;
	long long h=0,k=0;
	v.push_back(0);
	for(int i=1;i<=n;i++){
		v.push_back(a[i]);
		for(int j=1;j<=h;j++){
			v.push_back(v[j]+a[i]);
			if(v[j]+a[i]>a[i]*2){
				sum++;
			}
		}
		h+=pow(2,k);
		k++;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
