#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=a[i];
		if(s==k&&i==n) m++;
		for(int j=i+1;j<=n;j++){
			s^=a[j];
			if(s==k) m++;
		}
	}
	cout<<m;
	return 0;
}