#include<bits/stdc++.h>
using namespace std;
int a[100],ans=0,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxx&&n<=3){
		cout<<1;
		return 0;
	}
	else if(n<=3){
		cout<<0;
		return 0;
	}
	else{
		cout<<n;
	}
	return 0;
} 
