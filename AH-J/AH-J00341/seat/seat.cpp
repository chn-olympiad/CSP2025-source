#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,s=1;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int d;
		cin>>d;
		if(a<d)s++;
		}
		int l=(s-1)/n+1,h=(s-1)%n+1;
		if(h==0)h=n;
		cout<<l<<" ";
		if(l%2==1){
			cout<<h;
		}
		else{
			cout<<n-h+1;
		}
 return 0;
}
