#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+10];
	long long js=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3)cout<<0;
	else if(n==3){
		int max=-1;
		for(int i=0;i<n;i++){
			js+=a[i];
			if(max<a[i])max=a[i];
		}
		if(max*2<js)cout<<1;
		else cout<<0;
	}
	return 0;
}
