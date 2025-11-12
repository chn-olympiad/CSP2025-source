#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	int aaa[(n*m)+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>aaa[i];
	}
	int xxxr=aaa[1];
	int xxxr_sss;
	sort(aaa,aaa+(n*m));
	for(int i=n*m;i>=1;i--)
	{
		if(aaa[i]==xxxr)
		{
			xxxr_sss=i;
		}
	}
	if(n==1&&m!=1)
	{
		cout<<1<<" "<<xxxr_sss;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(xxxr_sss%n==0)
	{
		if((xxxr_sss/n)%2==0)
		{
			cout<<xxxr_sss/2<<" "<<1;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else
		{
			cout<<xxxr_sss/2<<" "<<m;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
