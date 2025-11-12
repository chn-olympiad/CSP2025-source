#include <iostream>
using namespace std;
int a[1000000];
bool c[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt =1,max=0;
	int cnt0=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;
	string b;
	cin>>b;
	int n = b.size();
	for(int i=0;i<=n;i++)
	{
		if('0'<=b[i]<='9')
		{
			a[cnt] = b[i]-48;
			c[cnt] = true;
			cnt++;
			
		}
		if(b[i]>=max)
		{
			max = b[i]-48;
		}	
	}

    for(int i=1;i<=n;i++) 
    {
    	if(c[i])
    	{
    		
    		
    		if(a[i] == 0)
    		{
    			cnt0++;
    			continue;
			}
			if(a[i] == 1)
    		{
    			cnt1++;
    			continue;
			}
			if(a[i] ==2)
    		{
    			cnt2++;
    			continue;
			}
			if(a[i] == 3)
    		{
    			cnt3++;
    			continue;
			}
			if(a[i] == 4)
    		{
    			cnt4++;
    			continue;
			}
			if(a[i] == 5)
    		{
    			cnt5++;
    			continue;
			}
			if(a[i] == 6)
    		{
    			cnt6++;
    			continue;
			}
			if(a[i] == 7)
    		{
    			cnt7++;
    			continue;
			}
			if(a[i]== 8)
			{
				cnt8++;
				continue;
			} 
			if(a[i] == 9)
    		{
    			cnt9++;
    			continue;
			}
		
		}
	}
	for(int i=1;i<=cnt9;i++)
	{
		cout<<9;
	}
	for(int i=1;i<=cnt8;i++)
	{
		cout<<8;
	}
	for(int i=1;i<=cnt7;i++)
	{
		cout<<7;
	}
	for(int i=1;i<=cnt6;i++)
	{
		cout<<6;
	}
	for(int i=1;i<=cnt5;i++)
	{
		cout<<5;
	}
	for(int i=1;i<=cnt4;i++)
	{
		cout<<4;
	}
	for(int i=1;i<=cnt3;i++)
	{
		cout<<3;
	}
	for(int i=1;i<=cnt2;i++)
	{
		cout<<2;
	}
	for(int i=1;i<=cnt1;i++)
	{
		cout<<1;
	}
	for(int i=1;i<=cnt0;i++)
	{
		cout<<0;
	}
	return 0;
	
}

