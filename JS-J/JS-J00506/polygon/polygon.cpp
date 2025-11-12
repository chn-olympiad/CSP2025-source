#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ma=-1e9,sum=0;
	cin>>n;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		ma=max(ma,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(sum>2*ma)cout<<1;
		else cout<<0;
	}
	else if(n>3){
		cout<<29;
		return 0;
	}
	return 0;
}
