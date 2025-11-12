#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[4];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
		cout<<"1";
	else 
		cout<<"0";
	return 0;
}
//阿弥陀佛，上善若水 
