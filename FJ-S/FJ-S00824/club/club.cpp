#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>>q1;
priority_queue<pair<int,int>>q2;
priority_queue<pair<int,int>>q3;
int n,a[100010][5],m[100010],s[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(s,0,sizeof(s));
		memset(m,0,sizeof(m));
		memset(a,0,sizeof(a));
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		cin>>n;
		int answer=0;
		int k=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];	
			if((a[i][2]<=a[i][1]&&a[i][1]<=a[i][3])||(a[i][3]<=a[i][1]&&a[i][1]<=a[i][2]))s[i]=1;
			else if((a[i][1]<=a[i][2]&&a[i][2]<=a[i][3])||(a[i][3]<=a[i][2]&&a[i][2]<=a[i][1]))s[i]=2;
			else s[i]=3;
			if(a[i][1]>=max(a[i][2],a[i][3])&&s[i]!=1)m[i]=1;
			else if(a[i][2]>=max(a[i][1],a[i][3])&&s[i]!=2)m[i]=2;
			else m[i]=3;
		}
		for(int i=1;i<=n;i++)
		{
			if(m[i]==1)
			{
				if((int)q1.size()<k)q1.push(make_pair(-a[i][m[i]],i)),answer+=a[i][m[i]];
				else
				{
					int rei=q1.top().second;
					int answer1=answer+a[i][s[i]],answer2=answer-a[rei][m[rei]]+a[i][m[i]]+a[rei][s[rei]];
					if(answer1<answer2)
					{
						q1.pop();
						q1.push(make_pair(-a[i][m[i]],i));
						if(s[rei]==2)q2.push(make_pair(-a[rei][s[rei]],rei));
						else q3.push(make_pair(-a[rei][s[rei]],rei));
						answer=answer2;
					}
					else
					{
						if(s[i]==2)q2.push(make_pair(-a[i][s[i]],i));
						else q3.push(make_pair(-a[i][s[i]],i));
						answer=answer1;
					}
				}
			}
			if(m[i]==2)
			{
				if((int)q2.size()<k)q2.push(make_pair(-a[i][m[i]],i)),answer+=a[i][m[i]];
				else
				{
					int rei=q2.top().second;
					int answer1=answer+a[i][s[i]],answer2=answer-a[rei][m[rei]]+a[i][m[i]]+a[rei][s[rei]];
					if(answer1<answer2)
					{
						q2.pop();
						q2.push(make_pair(-a[i][m[i]],i));
						if(s[rei]==1)q1.push(make_pair(-a[rei][s[rei]],rei));
						else q3.push(make_pair(-a[rei][s[rei]],rei));
						answer=answer2;
					}
					else
					{
						if(s[i]==1)q1.push(make_pair(-a[i][s[i]],i));
						else q3.push(make_pair(-a[i][s[i]],i));
						answer=answer1;
					}
				}
			}
			if(m[i]==3)
			{
				if((int)q3.size()<k)q3.push(make_pair(-a[i][m[i]],i)),answer+=a[i][m[i]];
				else
				{
					int rei=q3.top().second;
					int answer1=answer+a[i][s[i]],answer2=answer-a[rei][m[rei]]+a[i][m[i]]+a[rei][s[rei]];
					if(answer1<answer2)
					{
						q3.pop();
						q3.push(make_pair(-a[i][m[i]],i));
						if(s[rei]==1)q1.push(make_pair(-a[rei][s[rei]],rei));
						else q2.push(make_pair(-a[rei][s[rei]],rei));
						answer=answer2;
					}
					else
					{
						if(s[i]==1)q1.push(make_pair(-a[i][s[i]],i));
						else q2.push(make_pair(-a[i][s[i]],i));
						answer=answer1;
					}
				}
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
