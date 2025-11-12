#include<bits/stdc++.h>
#include<queue> 
using namespace std; 
long long n,m,k,xxsit,yysit,score;
priority_queue<int>r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>k;
			if(i==1&&j==1)
			{
				score=k;
			}
			r.push(k);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				xxsit=i;
				yysit=j;
				if(r.top()!=score)
				{
					r.pop();
				}
				else
				{
					cout<<xxsit<<" "<<yysit<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(int p=1;p<=m;p++)
			{
				xxsit=i;
				yysit=p;
				if(r.top()!=score)
				{
					r.pop();
				}
				else
				{
					cout<<xxsit<<" "<<yysit<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

