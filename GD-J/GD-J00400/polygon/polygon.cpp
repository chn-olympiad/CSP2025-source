#include<bits/stdc++.h>
using namespace std;
int n,a[5050],c=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		c*=a[i];
		c%=998244353;
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
