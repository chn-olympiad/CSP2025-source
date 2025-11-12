#include<bits/stdc++.h>
using namespace std;
int n,r;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans;
	cin>>n;
	if(n<3)cout<<0;
	else if(n==3)cout<<1;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

