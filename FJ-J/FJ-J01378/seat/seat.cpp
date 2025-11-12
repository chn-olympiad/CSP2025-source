#include<bits/stdc++.h>
using namespace std;
struct student{
	int id,score;
}a[10005];
int n,m;
bool cmp(student q,student p)
{
	return q.score>p.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);	
	cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		a[i].id=i;
		cin>>a[i].score;
	}
	sort(a+1,a+1+n*m,cmp);
	int ansn=1,ansm=1,jia=1;
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i].score<<" "<<ansn<<" "<<ansm<<"\n";
		if(a[i].id==1)
		{
			cout<<ansn<<" "<<ansm;
			return 0;
		}
		if((ansm==m&&jia==1)||(ansm==1&&jia==-1))
		{
			jia=-jia;
			ansn++;
		}
		else
		{
			ansm+=jia;
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
