#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=0,n,sum=0,maxl=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		sum+=a[i];
		if(a[i]>maxl) maxl=a[i];
	}
	if(sum>maxl*2) ans++;
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
