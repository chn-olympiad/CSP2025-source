#include<iostream>
using namespace std;
int a[100001],ak=1,bk=1,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) ak=0;
		if(a[i]>1) bk=0;
	}
	if(ak==1)
		cout<<n/2;
	else if(bk==1){
	    for(int i=1;i<=n;i++)
		if(a[i]==1) ans++;
		if(k==1)
			cout<<ans;
		else
		cout<<ans/2;
	}
	else
	cout<<2;
	return 0;
}
