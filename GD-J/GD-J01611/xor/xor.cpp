#include<bits/stdc++.h>
using namespace std;
int n,k,a[555555],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	 for(int j=i;j<=n;j++){
	 	int x=a[i];
	 	for(int z=i+1;z<=j;z++) x=x^a[z];
	 	if(x==k) sum++,i=j+1;
	 }
	cout<<sum;
	return 0;
}
