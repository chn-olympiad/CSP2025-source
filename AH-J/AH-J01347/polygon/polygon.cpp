#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100000],b[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			k++;
		}
		if(a[1]+a[3]>a[2]){
			k++;
		}
		if(a[2]+a[3]>a[1]){
			k++;
		}
	}
	cout<<k;
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
