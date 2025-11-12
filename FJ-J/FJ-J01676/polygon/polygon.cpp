#include<bits/stdc++.h>
using namespace std;
int n,a[5010],m;
long long s,z;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		m=a[i];
		for(int j=3;j<=n;j++){
			s+=a[j];
			if(s>m*2&&m>a[j]) z++;
		}
	}
	cout<<z%998244353;
	return 0;
}