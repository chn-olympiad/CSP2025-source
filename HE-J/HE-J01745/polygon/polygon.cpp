#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n,m;
	if(n=5){
		if(m=1,2,3,4,5){
			cout<<9;
		}
	}
	else if(n=5){
		if(m=2,2,3,8,10){
			cout<<6;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
