#include<bits/stdc++.h>
using namespace std;
string a;
int b[100005],ans=0;
long long num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<=l-1;i++)
	{
		if(a[i]=='1')
		{	
			ans++;
			b[ans]=1;	
		}
		else if(a[i]=='2')
		{
			ans++;
			b[ans]=2;
		}
		else if(a[i]=='3')
		{
			ans++;
			b[ans]=3;	
		}
		else if(a[i]=='4')
		{
			ans++;
			b[ans]=4;
		}
		else if(a[i]=='5')
		{
			ans++;
			b[ans]=5;
		}
		else if(a[i]=='6')
		{
			ans++;
			b[ans]=6;
		}
		else if(a[i]=='7')
		{
			ans++;
			b[ans]=7;
		}
		else if(a[i]=='8')
		{
			ans++;
			b[ans]=8;
		}
		else if(a[i]=='9')
		{
			ans++;
			b[ans]=9;
		}
		else if(a[i]=='0')
		{
			ans++;
			b[ans]=0;
		}
	}
	long long q=1;
	sort(b+1,b+1+ans);
	for(int i=1;i<=ans;i++)
	{
		num=num+b[i]*q;
		q=q*10;
	}
	cout<<num;
	return 0;
}
