#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100010];
void ans(int x,int maxx,int sum){
	if(x==n){
		if(sum>maxx*2)t++;
		return; 
	}
	else {
		ans(x+1,max(maxx,a[x]),sum+a[x]);
		ans(x+1,maxx,sum);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ans(0,0,0);
	cout<<t;
	return 0;
}
 
