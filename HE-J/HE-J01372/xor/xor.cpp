#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	int n,k,b=0,c,d,e,f,u=1;
	cin>>n>>k;
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	c=a[0],d=a[1];
	if(c^d==k)
		b++;
	for(int i=0;i<n;i++){
		if(a[i]==k)
			b++;
	}
	cout<<b;
	return 0;
	}
