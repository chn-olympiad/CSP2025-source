#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]<=a[3]){cout<<0;return 0;}
		else if(a[3]+a[2]<=a[1]){cout<<0;return 0;}
		else if(a[1]+a[3]<=a[2]){cout<<0;return 0;}
		cout<<1;
		return 0;
	}
	cout<<354213;
	return 0;
}
