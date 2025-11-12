#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c,ans=0;
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}