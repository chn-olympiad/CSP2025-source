#include<bits/stdc++.h>
using namespace std;
int a[5003];
int cnt,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
		sum+=a[i];
	}
	if(n<3) cout<<0;
	else if(n==3&&sum>(cnt*2)) cout<<1;
	return 0;
} 