#include<bits/stdc++.h>
using namespace std;
int a[115];
bool cmp(int a,int b)
{
	return a>b;	
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r;
 	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+nm+1,cmp);
	int h=1,l=1;
	bool ud=1;
	for(int i=1;i<=nm;i++)
	{
		if(ud)
		{
			if(a[i]==r)
			{
				cout<<l<<" "<<h<<endl;
			}
			if(i%n==0)
			{
				l++;
				h=n;
				ud=0;
				continue; 
			}
			h++;
		}
		else
		{
			if(a[i]==r)
			{
				cout<<l<<" "<<h<<endl;
			}
			if(i%n==0)
			{
				l++;
				h=1;
				ud=1;
				continue; 
			}
			h--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
