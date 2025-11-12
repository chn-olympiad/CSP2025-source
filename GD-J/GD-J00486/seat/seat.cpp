#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[11][11];
int t=1;
int targetwhere;
struct node
{
	int score;
	bool istarget=0;
};	
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	node per[p+1]={};
	for(int i=1;i<=p;i++)
	{
		cin>>per[i].score;
		if(i==1) per[i].istarget=true;
	}
	for(int i=1;i<p;i++) for(int j=i;j<p;j++)
	{
		if(per[i].score<per[j].score) swap(per[i],per[j]);
	}
	int hang=1;
	for(int i=1;i<=p;i++) 
	{
		if(per[i].istarget) targetwhere=i;
	}
	for(int j=1;j<=m;j++)
	{
		if(hang==1)
		{
			for(hang=1;hang<=n;hang++)
			{
				if(targetwhere==t)
				{
					cout<<j<<" "<<hang;
					return 0;
				}
				t++;
			}
		}
		else
		{
			for(hang=n;hang>0;hang--)
			{		
				if(targetwhere==t)
				{
					cout<<j<<" "<<hang;
					return 0;
				}
				t++;
			}
		
		}
	//t++;
	}
	/*for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(a[i][j])
		{
			cout<<i<<" "<<j;
			return 0;
		}  
	}*/
	return 0;
}
