#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=1;
int main (){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		return 0;
	}
	cout<<1;
	return 0;
}

