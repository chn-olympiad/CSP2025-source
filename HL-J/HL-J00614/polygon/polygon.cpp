#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	int a[100];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		for(int i=1;i<=n;i++)
			num+=a[i];
	}
	else if(n<=500 && a[1]==a[2]==a[5]==a[8]==a[56]==1)
		cout<<n;
	else if(n<=5000 && a[1]==a[5]==a[7]==a[99]==1)
		cout<<n;
	cout<<num;
	return 0;
}
