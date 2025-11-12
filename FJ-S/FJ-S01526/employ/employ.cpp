#include<bits/stdc++.h>
using namespace std;

long long n,m,l,sum=1;
string k;
long long a[505];

int main(){
	/*
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	*/
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			l++;
	}
	n-=l;
	for(int i=1;i<=m;i++){
		sum*=(n-i+1);
		sum%=998244353;
		sum/=i;
	}
	for(int i=2;i<=m;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
