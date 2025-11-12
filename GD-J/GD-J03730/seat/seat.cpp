#include<bits/stdc++.h>
using namespace std;
const int M=12;
int n,m,c,r;
int a,t,l;
int v[114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a=n*m;
	for(int i=1;i<=a;i++) cin>>v[i];
	t=v[1];
	sort(v,v+a+1);
	for(int i=1;i<=a;i++){
		if(v[i]==t) l=a-i+1;
	}
	c=(l-1)/n;
	r=c%2?n-(l-1)%n:(l-1)%n+1;
	cout<<c+1<<' '<<r;
	fclose(stdin);fclose(stdout);
	return 0;
}
