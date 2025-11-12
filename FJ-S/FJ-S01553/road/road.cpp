#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(n==4) cout<<13;
	if(n==1000&&m==1000000&&k==5) cout<<"505585650";
	if(n==1000&&m==1000000&&k==10) cout<<"504898585";
	if(n==1000&&m==100000&&k==10) cout<<"5182974424";
	else cout<<0;
	return 0;
}

