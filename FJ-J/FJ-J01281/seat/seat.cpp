#include<bits/stdc++.h> 
using namespace std;
bool is_O(int a)
{
	if(a<=1)
	{
		return false;
	}
	if(a%2==0)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int Score[n*m+1],NS[n*m+1];
	for(int i = 1;i<=n*m;i++)
	{
		cin>>Score[i];
	}
	int MY = Score[1];
	int Num = 0;
	sort(Score+1,Score+n*m+1);
	int w = 1;
	for(int i = n+m;i>=1;i--)
	{
		NS[w] = Score[i];
		w++;
	} 
	for(int i = 1;i<=n*m;i++)
	{
		if(NS[i] == MY)
		{
			Num = i;
		}
	}
	int TEMP = 1;
	for(int h = 1;h<=n;h++)
	{
		if(is_O(h))
		{
			for(int l = m;l>1;l--)
			{
				if(TEMP == Num)
				{
					cout<<h<<" "<<l;
				}
				TEMP = TEMP + 1;
			}
		}
		else
		{
			for(int l = 1;l<=m;l++)
			{
				if(TEMP == Num)
				{
					cout<<h<<" "<<l;
				}
				TEMP = TEMP + 1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
