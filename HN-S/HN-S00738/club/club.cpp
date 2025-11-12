#include<bits/stdc++.h>
using namespace std;
int b,t,n,m,c,h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int a[10001],i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j];
			c=b=max(a[i],a[j]);
			
		}
		h=m=2*b;
		
	}
	
	cout<<h+m;


	return 0;
}
