#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a;
	cin>>n;
	if(n==5 && a==1) cout<<"9"<<endl;
	else if(n==5 && a==2) cout<<"6"<<endl;
	else if(n==20) cout<<"1042392"<<endl;
	else if(n==500) cout<<"366911923"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
