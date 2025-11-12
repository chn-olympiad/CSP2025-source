#include<bits/stdc++.h>
using namespace std;
struct stu{int index,score;};
stu s[105];
stu tong[105];
stu t[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,Rn=1,Rm=1,Ri=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].score;
		s[i].index=i;
		tong[s[i].score]=s[i];
	}
	int j=1;
	for(int i=100;i>=0;i--)
	{
		if(tong[i].index) t[j++]=tong[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		Ri++;
		if(t[i].index==1)
		{
			cout<<Rm<<' '<<Rn;
			break;
		}
		else if(Rm%2)
		{
			if(Rn==n) Rm++;
			else Rn++;
		}
		else
		{
			if(Rn==1) Rm++;
			else Rn--;
		}
	}
	return 0;	
} 