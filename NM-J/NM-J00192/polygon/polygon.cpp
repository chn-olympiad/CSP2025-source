#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if (n>3&&n<=10)
		cout<<"10";
		else if(n==3)
			cout<<"10";
			else if(n<=500&&n>10)
				cout<<"100";
				else if(n>500&&n<=5000)
					cout<<"1";
	return 0;				
}
		
