#include <bits/stdc++.h>
using namespace std;
int y[1000000];
int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int a=1,b=0,t,nu=0;
	string s;
	cin>>s;
    cout<<s[1];
	for(int i=0;i<s.size();i++)
	{

        y[i]=s[i]-'0';
	}


    	while(b==1)
	{
		for(int i=0;i<a;i++)
		{
			cout<<y[i]<<y[i+1]<<endl;
			if(y[i]<y[i+1])
			{
				t=y[i];
				y[i]=y[i+1];
				y[i+1]=t;
				nu++;
			}
		}
		if(nu==0)
		{
			b++;
		}
	}
			for(int i=0;i<a;i++)
	{
		cout<<y[i];
	}

	return 0;
}
