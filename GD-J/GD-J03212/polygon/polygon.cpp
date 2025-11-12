#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,c=0;
	cin>>n;
	int a[n];
	for(long long i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]>=1) c++;
	}
	cout<<c-2;
	fclose(stdin);
	fclose(stdout);
}
