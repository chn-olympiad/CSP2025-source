#include<bits/stdc++.h>
using namespace std;
long long a[10000],n,k,ma=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long s=0;
		for(int j=i;j<=n;j++){
			if(a[j]|a[j+1]==1)s++;
			if(s>ma)ma=s;
		}
	}
	cout<<ma;
	return 0;
}
