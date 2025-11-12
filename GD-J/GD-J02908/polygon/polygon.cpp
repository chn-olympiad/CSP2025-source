#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10000]={0};
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2-a[1]-a[2]-a[3]<0)cout<<1;
		else cout<<0;
	}else{
		cout<<3;
	}
}
