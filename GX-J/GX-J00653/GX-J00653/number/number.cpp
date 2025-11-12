#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string r[101];
	int n=0,a=s.size();
	for(int i=1;i<=a;i++)
	{
		cout<<n<<" ";
		if(s[i]==0)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i-1]==1)
		{
			r[n]=s[i-1];
			n++;
			cout<<1;
		}
		else if(s[i]==2)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==3)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==4)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==5)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==6)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==7)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==8)
		{
			r[n]=s[i];
			n++;
		}
		else if(s[i]==9)
		{
			r[n]=s[i];
			n++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<r[i];
	return 0;
}
