#include<bits/stdc++.h>
using namespace std;
const int MAXPaiNe=100014;

long long ans=0;
int j[3];int max_manii;
int t=0,n=0,k1,k2,k3;

struct stu
{
	int man1,man2,man3;
}oliver[MAXPaiNe];//manii do;

stu temp;

void com(int i,int j)
{
	temp.man1=oliver[i].man1;
	temp.man2=oliver[i].man2;
	temp.man2=oliver[i].man3;
	oliver[i].man1=oliver[j].man1;
	oliver[i].man2=oliver[j].man2;
	oliver[i].man3=oliver[j].man3;
	oliver[j].man1=temp.man1;
	oliver[j].man2=temp.man2;
	oliver[j].man3=temp.man3;
}

void babbuboi(int rely,int len)
{
	ans=0;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(rely==1&&oliver[i].man1<oliver[j].man1) com(i,j);
			if(rely==2&&oliver[i].man2<oliver[j].man2) com(i,j);
			if(rely==3&&oliver[i].man3<oliver[j].man3) com(i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
        max_manii=max( max( oliver[i].man1, oliver[i].man2 ),max( oliver[i].man2, oliver[i].man3 ));
		if(max_manii==oliver[i].man1)
		{
			j[0]++;
			ans+=oliver[i].man1;
		}
		else if(max_manii==oliver[i].man2)
		{
			j[1]++;
			ans+=oliver[i].man2;
		}
		else if(max_manii==oliver[i].man3)
		{
			j[2]++;
			ans+=oliver[i].man3;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		ans=0;
		cin>>n;
		memset(j,0,sizeof(j));
		for(int i=0;i<n;i++)
		{
			cin>>k1>>k2>>k3;
			oliver[i].man1=k1;
			oliver[i].man2=k2;
			oliver[i].man3=k3;
		}//check in

		for(int i=0;i<n;i++)
		{
			max_manii=max( max( oliver[i].man1, oliver[i].man2 ),max( oliver[i].man2, oliver[i].man3 ));
			if(max_manii==oliver[i].man1)
			{
				j[0]++;
				ans+=oliver[i].man1;
			}
			else if(max_manii==oliver[i].man2)
			{
				j[1]++;
				ans+=oliver[i].man2;
			}
			else if(max_manii==oliver[i].man3)
			{
				j[2]++;
				ans+=oliver[i].man3;
			}

		}
		//step01
		if(j[0]>(n/2)) babbuboi(1,n);
		if(j[1]>(n/2)) babbuboi(2,n);
		if(j[2]>(n/2)) babbuboi(3,n);
		cout<<ans<<endl;
	}
	return 0;
}
