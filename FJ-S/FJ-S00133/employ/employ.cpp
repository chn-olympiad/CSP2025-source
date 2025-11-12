#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m,a[1000]; 
	cin>>n>>m;
	bool s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((n=1)&&(m=1)&&(s="1"))
	{
		cout<<1<<endl;
	}
	else if((n=1)&&(m=1)&&(s="0"))
	{
		cout<<0<<endl;
	}
	return 0;
}
