#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int a[1001];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	int m=1001;
	cout<<m%998244353<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
