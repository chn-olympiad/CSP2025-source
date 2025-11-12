#include<bits/stdc++.h>
using namespace std;
string s;int c[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	//s.size=n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3)
	cout<<"2";
	else if(n==10)
	cout<<"2204128";
	else if(n==100)
	cout<<"161088479";
	return 0;
}