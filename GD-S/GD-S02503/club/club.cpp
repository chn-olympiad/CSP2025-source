#include <bits/stdc++.h>
using namespace std;
int t,n;
int smax[4];
struct stu{
	int sl[4];
	int love[4];
	bool vis=0;
}s[100000];
struct stu2{
	int sl[4];
	int love[4];
	bool vis=0;
	int bh;
}s2[100000];
bool cmp(stu2 a,stu2 b)
{
	return a.sl[1]>b.sl[1];
}

int main()
{

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int sum=0;
		cin>>n;
		smax[1]=n/2;
		smax[2]=n/2;
		smax[3]=n/2;
		int x1,x2,x3;
		for(int j=1;j<=n;j++)
		{
			int maxn=0;
			cin>>x1>>x2>>x3;
			s[j].sl[1]=x1;
			s[j].sl[2]=x2;
			s[j].sl[3]=x3;
			maxn=max(x1,x2);
			maxn=max(maxn,x3);
			if(maxn==x1)
			{
				s[j].love[1]=1;
				if(max(x2,x3)==x2)
				{
					s[j].love[2]=2;
					s[j].love[3]=3;
				}
				else{
					s[j].love[2]=3;
					s[j].love[3]=2;
				}
			}
			else if(maxn==x2)
			{
				s[j].love[1]=2; 
				if(max(x1,x3)==x1)
				{
					s[j].love[2]=1;
					s[j].love[3]=3;
				}
				else{
					s[j].love[2]=3;
					s[j].love[3]=1;
				}
			}
			else 
			{
				s[j].love[1]=3;
				if(max(x1,x2)==x1)
				{
					s[j].love[2]=1;
					s[j].love[3]=2;
				}
				else{
					s[j].love[2]=2;
					s[j].love[3]=1;
				}
			}
			s2[j].bh=j;
			s2[j].love[1]=s[j].love[1];
			s2[j].love[2]=s[j].love[2];
			s2[j].love[3]=s[j].love[3];
			s2[j].sl[1]=x1;
			s2[j].sl[2]=x2;
			s2[j].sl[3]=x3;
		}
		/*int temp1,temp2,temp3;
		int stemp1[1000000],stemp2[1000000],stemp3[1000000];
		for(int j=1;j<=n;j++)
		{
			
			if(stu[j].love[1]==1)
			{
				temp1++;
				stemp1[temp1]=j;
			}
			else if(stu[j].love[1]==2)
			{
				temp2++;
				stemp2[temp2]=j;
			}
			else {
				temp3++;
				stemp3[temp3]=j;
			}
		}
		if(temp1>smax[1])
		{
			sort(s2+1,s2+1+n,cmp);
			for(int j=smax[1]+1;j<=n;j++)
			{
				s[s2.bh].love
			}
		}*/
		if(n==2)
		{
			for(int j=1;j<=2;j++)
			{
				if(smax[s[j].love[1]]!=0)
				{
					sum+=s[j].sl[s[j].love[1]];
					smax[s[j].love[1]]--;	
				}
				else{
					if(s[j].sl[s[j].love[2]]==0)
					{
						sum=s[j-1].sl[s[j-1].love[2]]+s[j].sl[s[j].love[1]];
					}
			}
			}
			
		}
		else{
			for(int j=1;j<=n;j++)
			{
				sum+=s[j].sl[s[j].love[1]];
			}
		}
		
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
