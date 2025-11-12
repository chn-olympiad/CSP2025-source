#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=105;
struct node
{
	int score;
	int id;
}p[maxn];
bool cmp(node x,node y)
{
	return x.score>y.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>p[i].score;
		p[i].id=i;
	}
	sort(p+1,p+len+1,cmp);
	int cnt=0;
	for(int i=1;i<=len;i++)
	{
		if(p[i].id==1)
		{
			cnt=i;
			int c=cnt/n+1;
			int r;
			if(cnt%n==0)
			{
				c--;
				if(c%2!=0)
				{
					r=n;
				}
				else if(c%2==0) r=1;
			}
			else
			{
				if(c%2!=0)
				{
					r=cnt%n;
				}
				else if(c%2==0)
				{
					r=n-cnt%n+1;
				}
			}
			cout<<c<<" "<<r;
			break;
		}
	}
	
	return 0;
}
