#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=3,sum=0,max0=0;
	cin>>n;
	int sticks[n];
	for(int i=0;i<n;i++){
		cin>>sticks[i];
		max0=max(max0,sticks[i]);
		sum+=sticks[i];
	}
	if(2*max0<sum){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
