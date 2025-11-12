#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(n==3){
		if(sum>a[1]) cout<<1;
		else         cout<<0;
	}
	else cout<<sum/n;
	return 0;
}

