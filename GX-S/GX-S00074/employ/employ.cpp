#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510];
string s;
long long jie(long long n){
	long long sum=1;
	while(n>0){
		sum=(sum*n)%998244353;
		n--;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)cin>>a[i];
	cout<<jie(n);
}
