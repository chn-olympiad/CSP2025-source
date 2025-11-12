#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,chahao,seat[12][12],hao;
struct stu{
	int score;
	int hao=0;
};
stu s[144];
bool cmp(stu a,stu b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].score;
	}
	chahao=s[1].score;
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].score==chahao)
		{
			hao=i;
			break;
		}
	}
	for(int i=1;i<=m;i+=2)
	{
		seat[n][i]=i*n;
		if(i*n==hao)
		{
			cout<<i<<" "<<n<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		for(int j=n-1;j>=1;j--)
		{
			seat[j][i]=seat[j+1][i]-1;
			if(seat[j][i]==hao)
			{
				cout<<i<<" "<<j<<endl;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	for(int i=2;i<=m;i+=2)
	{
		seat[1][i]=i*n;
		if(i*n==hao)
		{
			cout<<i<<" "<<n<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		for(int j=2;j<=n;j++)
		{
			seat[j][i]=seat[j-1][i]-1;
			if(seat[j][i]==hao)
			{
				cout<<i<<" "<<j<<endl;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
