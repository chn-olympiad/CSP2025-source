#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long mod=998244353;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>n;
	int sum=0,maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3){
		if(sum>2*maxx){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 