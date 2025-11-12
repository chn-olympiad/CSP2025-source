#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum>a[n]*2)cout<<1;
	else cout<<0;
	return 0;
} 

