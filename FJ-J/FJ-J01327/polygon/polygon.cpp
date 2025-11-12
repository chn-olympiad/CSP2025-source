#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,n,sum=0,max=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n;
		sum+=n;
		if(n>max)max=n;
	}
	int s=max*2;
	if(sum>s&&n)cout<<1;
	else cout<<0;
	return 0;
} 
