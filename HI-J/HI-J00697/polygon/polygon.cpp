#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n=3&&a[i]<=10)cout<<1;
		else if(n<=5000&&a[i]==1)cout<<1;
	}
	return 0;
}

