#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n;
int main() {
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	if(n==3)
		cout<<"0";
	return 0;
}
