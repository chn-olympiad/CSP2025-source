#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,q=0,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
	}
	for(int i=m;i<=n;i++){
		int b=1;
		for(int j=i;j<=n;j++){
			b*=j;
		}
		q+=b;
	}
	cout<<q;
	return 0;
} 
