#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[20001],b=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b+=i;
	}
	cout<<b-n-1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
