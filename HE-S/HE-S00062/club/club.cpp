#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a1,a2,a3;
	int x;
}a[500005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1 >>a[i].a2 >>a[i].a3 ;
		}
		
	}
	int b1,b2,b3;
	int c1,c2,c3;
	if(n==2){
		for(int i=1;i<=n;i++){
			b1=max(a[i].a1 ,a[i-1].a1 );
			b2=max(a[i].a2 ,a[i-1].a2 );
			b3=max(a[i].a3 ,a[i-1].a3 );
			
		}
		
		c1=b1+b2;
		c2=b1+b3;
		c3=b2+b3;
		c2=max(c1,c2);
		c3=max(c2,c3);
		cout<<c3;
		return 0;
	}
	
	return 0;
}
