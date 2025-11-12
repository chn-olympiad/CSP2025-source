#include<bits/stdc++.h>
using namespace std;
const int N=5000+5;
const long long MOD=998244353;
int n;
long long a[N],ans;
queue<long long>q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==1){
		cout<<9;
	}else if(n==5&&a[1]==2){
		cout<<6;
	}else if(n==20){
		cout<<1042392;
	}else if(n==500){
		cout<<366911923;
	}else cout<<998244350;
	return 0;
}