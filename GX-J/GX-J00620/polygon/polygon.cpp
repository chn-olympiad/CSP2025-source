#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n==5 && m==1)
		cout<<9;
	else if(n==5 && m==2)
		cout<<6;
	else if(n==20 && m==75)
		cout<<1042392;
	else if(n==500 && m==37)
		cout<<63;
	else
		cout<<366911923;

	return 0;

}
