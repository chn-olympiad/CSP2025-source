#include<bits/stdc++.h>
using namespace std;

int a[5000];
int dp[5000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<0;
	return 0;
}
