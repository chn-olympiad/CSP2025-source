#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[123],b=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b++;
	}
	cout<<b%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
