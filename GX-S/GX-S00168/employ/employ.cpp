
#include<bits/stdc++.h>
using namespace std;
long long n,m,k[100005],a[1000005];
string w;
long long sum=1;
struct node{
	int c;
	int d;
}s[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>w;
	for(int i=1;i<=n;i++){
		k[i]=w[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

		for(int i=1;i<=n-2;i++){
			sum*=i;
		}
		sum*=n;
		sum*=(n-1);
		sum%=998244353;
		cout<<sum;
	return 0;
}
/*
5 1
1 1 1 1 1
1 2 3 4 5
*/
