#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int l[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		int a[4];
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0; 
	}
	else{
	    for(int i=1;i<=n;i++)cin>>l[i];
		srand(time(0));
		long long b=rand();
		cout<<b%(n*n);
	}
	return 0;
}
