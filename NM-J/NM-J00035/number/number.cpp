#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int a[1000000]={0};
    int b[1000000]={0};
    string s;
    cin>>s;
    int w=s.size();
    for(int i=0;i<s.size();i++)
    {
		//cout<<s[i]<<endl;
        if(s[i]=='1')
        {
            a[1]=1;
            b[i]++;
        }
        else if(s[i]=='2')
        {
			a[2]=2;
			b[i]++;
		}
		else if(s[i]=='3')
        {
			a[3]=3;
			b[i]++;
		}
		else if(s[i]=='4')
        {
			a[4]=4;
			b[i]++;
		}
		else if(s[i]=='5')
        {
			a[5]=5;
			b[i]++;
		}
		else if(s[i]=='6')
        {
			a[6]=6;
			b[i]++;
		}
		else if(s[i]=='7')
        {
			a[7]=7;
			b[i]++;
		}
		else if(s[i]=='8')
        {
			a[8]=8;
			b[i]++;
		}
		else if(s[i]=='9')
        {
			a[9]=9;
			b[i]++;
		}
		else if(s[i]=='0')
		{
			a[0]=0;
			b[i]++;
		}
    }
    int  ans = 0;
    int qw = 0;
    for(int j=0;j<=9;j++)
    {
		if(a[j]==j) qw+=j*b[j];
	}
	if(qw==1)
	{
		for(int i=0;i<=9;i++)
		{
			if(a[i]==i)
			{
				cout<<a[i]<<endl;
				return 0;
			}
		}
	}
	int yu=1;
    for(int i=10;i>=0;i--)
    { 
		if(a[i]==i&&b[i]>0)
		{
			    
			
			for(int j=1;j<=b[i];j++)
			{	
				for(int p=1;p<=qw;p++)
				{
					yu*=10;
				}
				ans+=i*yu;
				yu = 1;
				qw--;
			}
		}
    }
    cout<<ans<<endl;
    return 0;
}
