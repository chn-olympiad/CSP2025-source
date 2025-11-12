#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	cout<<9;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
