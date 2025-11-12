#include<bits/stdc++.h>
using namespace std;
int c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,maxa=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		maxa=max(maxa,a);
		c+=a;
	}
	if(c>2*maxa)
		cout<<1;
	else cout<<0;
	return 0;
} 
