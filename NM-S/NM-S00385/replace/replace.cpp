#include<bits/stdc++.h>
using namespace std;
struct ui
{
	string x,y;
}num[9001001];
struct oi
{
	string a,b;
}que[9001001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i].x>>num[i].y;
	for(int i=1;i<=k;i++)
	{
		int ans=0;
		cin>>que[i].a>>que[i].b;
		
		for(int j=1;j<=n;j++)
		{
			int len=num[j].x.size();
			string temp;
			temp=que[i].a;
			int flag=0;
			if(que[i].a.size()<len)
				continue ;
			for(int k=0;k<=que[i].a.size()-len;k++)
			{
				temp=que[i].a;
				for(int l=0;l<len;l++)
				{
					if(que[i].a[k+l]!=num[j].x[l])
					{
						break;
					}
					else
						temp[k+l]=num[j].y[l];
				}
				if(temp==que[i].b)
				{
					ans++;
					break;
				}
			}
			if(flag==1)
				continue;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
