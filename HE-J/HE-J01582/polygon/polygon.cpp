#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],o=0;
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
		if(a[i]+a[j]>a[j+1]){
			o++;
		}
	}
}

cout<<o+2;
	return 0;
}
