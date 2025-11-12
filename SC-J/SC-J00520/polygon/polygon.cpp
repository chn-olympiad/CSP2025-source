#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	else if(n==3){
		int x,y,z;cin>>x>>y>>z;
		if((x+y)>z&&(x+z)>y&&(y+z)>x)cout<<"1";
		else cout<<"0";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}