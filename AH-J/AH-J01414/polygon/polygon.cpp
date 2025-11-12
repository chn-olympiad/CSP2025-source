#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}	
	int x=a[1]+a[2];
	if(x>a[3]&&n==3)cout<<1;
	return 0;
} 
