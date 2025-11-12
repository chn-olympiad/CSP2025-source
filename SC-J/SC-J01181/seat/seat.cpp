#include<bits/stdc++.h>
using namespace std;
int b[10001];
bool qq;
int res;
int ans;
int n;
int m;
int nm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		cin>>b[i];
	}
	res=b[1];
	sort(b+1,b+nm+1);
	ans=lower_bound(b+1,b+nm+1,res)-b;
/*
3 3
94 95 96 97 98 99 100 93 92	
*/
/*
2 2 
98 99 100 97
*/
	ans=nm-ans+1;
//	cout<<ans<<endl;
	int man=ans/n;
	int ba=ans%n;
//	cout<<man<<endl;
//	cout<<ba<<endl;
	if(ba!=0)
	{
		man++;
	}
	else
	{
		qq=true;
	}
	if(man%2==0 && ba==0)
	{
		ba=1;
	}
	else if(man%2!=0 && ba==0)
	{
		ba=n;
	}
/*
4 5
78 91 56 57 54 100 97 99 98 94 22 10 0 63 71 92 33 34 60 30
*/
	if(man%2==0)
	{
		cout<<man<<" ";
		if(qq==true)
		{
			cout<<ba;
		} 
		else
		{
			cout<<n-ba+1;
		}
	} 
	else
	{
		cout<<man<<" "<<ba;
	}
	return 0;
} 