#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500001],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(t==k)s++;
		for(int j=i+1;j<=min(n,i+1+k);j++)t|=a[i];
		if(t==k)s++;
	}
	cout<<s;
	return 0;
}