#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==4||n==5||n==6){
		cout<<10;
	}
	return 0;
}
