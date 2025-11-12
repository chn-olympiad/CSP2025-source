#include<bits/stdc++.h>
using namespace std;
int n,a[5555];
long long ans;
void Bl(int p,int k,int z){
	if(z>a[k]) ans=(ans+1)%998244353;
	for(int i=p;i<k;i++)
		Bl(i+1,k,z+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(i>=3) Bl(1,i,0);
	cout<<ans;
	return 0;
}
