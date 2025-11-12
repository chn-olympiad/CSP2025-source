#include<bits/stdc++.h>
using namespace std;
string s,n,a,v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin>>s;
	while(s!=0)
	{
		n=s%10;
		s=s/10;
		if(s==1||s==2||s==3||s==4||s==5||s==6||s==7||s==8||s==9||s==0)
		{
			v=s;
		}
	}
	cout<<max(v,a);
}


	
	
 
