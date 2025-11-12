#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a,a+n-1);
	if(n<3) cout<<0;
	else if(cnt<=a[n-1]*2) cout<<0;
	else if(n==3) cout<<1;
	else cout<<0;
	return 0;
}