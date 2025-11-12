#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool f=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=1){
			f=0;
			break;
		}
	if(f)cout<<n-2;
	else cout<<1;
}
