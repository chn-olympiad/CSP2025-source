#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cout<<n*(n+1)/2-2*n+1;
	return 0;
}
