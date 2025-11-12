#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,x,y,z,c=0;
	cin>>a>>b;
	for (int i=1;i<=a;i++){
		cin>>x>>y>>z;
		c+=z;
	}
	for (int i=1;i<=b;i++){
		for (int i=1;i<=a+1;i++){
			cin>>x;
		}
	}
	cout<<c;
	return 0;
}
