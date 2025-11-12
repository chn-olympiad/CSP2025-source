#include<bits/stdc++.h>
using namespace std;
int t,n,a[100002][3],c[100002][3],cp[3];
int cl1[100002],cl2[100002],cl3[100002],l1,l2,l3;
struct club
{
	int num=0,id=0;
};
bool cmp(club a,club b)
{
	return a.num<b.num;
}
bool rcmp(int a,int b)
{
	return a>b;
}
long long cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			club b[3];for(int j=0;j<3;j++){b[j].id=j;b[j].num=a[i][j];}
			sort(b,b+3,cmp);
			c[i][b[2].id]=b[2].num;
			c[i][b[1].id]=-1;
			c[i][b[0].id]=-1;
			//cnt+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		for(int i=0;i<n;i++)
		{
			cl1[i]=c[i][0];cl2[i]=c[i][1];cl3[i]=c[i][2];
			l1+=cl1[i]!=-1;l2+=cl2[i]!=-1;l3+=cl3[i]!=-1;
		}
		sort(cl1,cl1+n,rcmp);sort(cl2,cl2+n,rcmp);sort(cl3,cl3+n,rcmp);
		l1=0,l2=0,l3=0;
		for(int i=0;i<n;i++)
		{
			if(cl1[i]!=-1&&l1<n/2){cnt+=cl1[i];l1++;}
			if(cl2[i]!=-1&&l2<n/2){cnt+=cl2[i];l2++;}
			if(cl3[i]!=-1&&l3<n/2){cnt+=cl3[i];l3++;}
		}
		cout<<cnt;
	}
	return 0;
}
