#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b,c,d;
	cin>>n>>m;
	cin>>a>>b>>c>>d;
	if(a>=b>=c>=d){
		cout<<"1 1";
	}
	if(b>=a>=c>=d){
		cout<<"1 2";
	}
	if(c>=b>=a>=d){
		cout<<"2 1";
	}
	if(d>=b>=c>=a){
		cout<<"2 2";
	}
	return 0;
}
