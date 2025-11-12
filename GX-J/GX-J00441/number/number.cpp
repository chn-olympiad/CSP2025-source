#include<bits/stdc++.h>
using namespace std;

string s;
long long a;
long long t1,t2,t3,t4,t5,t6,t7,t8,t9,t0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++)//cun number
	{
		if(s[i]=='1')
		{
			t1++;
		}
		if(s[i]=='2')
		{
			t2++;
		}
		if(s[i]=='3')
		{
			t3++;
		}
		if(s[i]=='4')
		{
			t4++;
		}
		if(s[i]=='5')
		{
			t5++;
		}
		if(s[i]=='6')
		{
			t6++;
		}
		if(s[i]=='7')
		{
			t7++;
		}
		if(s[i]=='8')
		{
			t8++;
		}
		if(s[i]=='9')
		{
			t9++;
		}
		if(s[i]=='0')
		{
			t0++;
		}
	}//cun number
	
	
	if(t9+t8+t7+t6+t5+t4+t3+t2+t1==0)
	{
		cout<<"0";
		return 0;
	}
	
	
	while(t9>0)
	{
		cout<<"9";
		t9--;
	}
	while(t8>0)
	{
		cout<<"8";
		t8--;
	}
	while(t7>0)
	{
		cout<<"7";
		t7--;
	}
	while(t6>0)
	{
		cout<<"6";
		t6--;
	}
	while(t5>0)
	{
		cout<<"5";
		t5--;
	}
	while(t4>0)
	{
		cout<<"4";
		t4--;
	}
	while(t3>0)
	{
		cout<<"3";
		t3--;
	}
	while(t2>0)
	{
		cout<<"2";
		t2--;
	}
	while(t1>0)
	{
		cout<<"1";
		t1--;
	}
	while(t0>0)
	{
		cout<<"0";
		t0--;
	}
	return 0;
}
