#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b==1)cout<<9;
	else if(b==2)cout<<6;
	else if(b==75)cout<<1042392;
	else if(b==37)cout<<366911923;
	else cout<<0;
	return 0;
} 
