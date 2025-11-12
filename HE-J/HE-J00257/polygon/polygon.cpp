#include<bits/stdc++.h>
using namespace std;
int a[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ma=INT_MIN,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);sum+=a[i];
	}
	if(n<3||(sum<=2*ma)) cout<<0;
	else cout<<1;
	return 0;
}
