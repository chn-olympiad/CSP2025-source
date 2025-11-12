#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	double s;
	int a;
	cin>>s;
	for(int i=1;i<=s;i++){
		cin>>a;
		for(int j=i;j<=10;j++){
			if(a>=j)cout<<a;
		}
	}
	cout<<a;
	return 0;
} 
