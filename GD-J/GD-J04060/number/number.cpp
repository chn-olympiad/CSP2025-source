#include<bits/stdc++.h>
using namespace std;

int n[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

//	好玩 
	
	string s;
	cin>>s;
	int l=s.size();
	
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0')
		{
			n[0]++;
		}
		if(s[i]=='1')
		{
			n[1]++;
		}
		if(s[i]=='2')
		{
			n[2]++;
		}	
		if(s[i]=='3')
		{
			n[3]++;
		}	
		if(s[i]=='4')
		{
			n[4]++;
		}	
		if(s[i]=='5')
		{
			n[5]++;
		}
		if(s[i]=='6')
		{
			n[6]++;
		}
		if(s[i]=='7')
		{
			n[7]++;
		}	
		if(s[i]=='8')
		{
			n[8]++;
		}	
		if(s[i]=='9')
		{
			n[9]++;
		}		
	}
	
	for(int i=9;i>=0;i--)
	{
	//	cout<<n[i]<<"\n";
		int x=n[i];
		for(int j=x;j>0;j--)
		{
			cout<<i;		
		}		
	}
	
	
	return 0;//woc差点忘记写这个了
	 
}


