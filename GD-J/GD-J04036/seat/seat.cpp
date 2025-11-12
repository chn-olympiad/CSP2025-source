#include <bits/stdc++.h>
using namespace std;
int n,m,d,other_d,num_up,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>d;
	for(int i=2;i<=n*m;++i){
		scanf("%d",&other_d);
		num_up+=(other_d>d);
	}
	c=num_up/n+1;
	r=num_up%n+1;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r;
	cout<<endl;
	return 0;
}
