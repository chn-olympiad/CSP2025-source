#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[10000];
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+x);
	cout<<a[x];
} 
