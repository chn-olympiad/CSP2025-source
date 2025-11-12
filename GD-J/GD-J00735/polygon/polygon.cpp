#include<bits/stdc++.h>
using namespace std;
int a[100005],n,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon,in","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]==0)t++;
	if(t==n)cout<<"0";
	else cout<<"1";
	
	return 0;
}
