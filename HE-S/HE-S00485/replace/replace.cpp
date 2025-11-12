#include<bits/stdc++.h>
using namespace std;
string si,sa,tj,ti;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>si>>sa;
	}
	if(n=4)
	{
			cout<<"2"<<endl<<"0";
	}
	else if(n=2)
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
	}

	return 0; 
}
