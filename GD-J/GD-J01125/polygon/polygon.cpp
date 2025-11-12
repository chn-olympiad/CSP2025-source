#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100],sum=0,ma=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		ma=max(ma,a[i]);
	}
	if(sum>ma*2) cout<<1;
	else cout<<0;
	return 0;
}
