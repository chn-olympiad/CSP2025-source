#include<bits/stdc++.h>
using namespace std;
int st[11][11]={0},cj[105]={0};

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,change=0,lie=0,sum=0,q,w;
	cin>>n>>m;
	const int number=n*m;
	for(int i=0;i<number;i++)
	{
		cin>>cj[i];
	}
	const int R=cj[0];
	for(int x=0;x<number;x++)
	{
		for(int y=0;y<number;y++)
		{
			change=max(cj[y+1],cj[y]);
			if(cj[y]<change)
			{
				cj[y+1]=cj[y];
				cj[y]=change;
			}
		}
	}
	/*for(int lll=0;lll<number;lll++)
	{
		cout<<cj[lll]<<" ";
	}
	cout<<endl;*/ 
	while(lie<=m)
	{
		for(int b=0;b<n;b++)
		{
			st[b][lie]=cj[sum];
			sum++;
		}
		if(sum>=number)
		{
			break;
		}
		lie++;
		for(int c=n-1;c>=0;c--)
		{
			st[c][lie]=cj[sum];
			sum++;
		}
		if(sum>=number)
		{
			break;
		}
		lie++;
	}
	/*for(int gu=0;gu<n;gu++)
	{
		for(int gf=0;gf<m;gf++)
		{
			cout<<st[gu][gf]<<" ";
		}
		cout<<endl;
	}*/
	for(int sy=0;sy<n;sy++)
	{
		for(int sr=0;sr<m;sr++)
		{
			if(st[sy][sr]==R)
			{
				q=sy+1;
				w=sr+1;
				break;
			}
		}
	}
	cout<<w<<" "<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
