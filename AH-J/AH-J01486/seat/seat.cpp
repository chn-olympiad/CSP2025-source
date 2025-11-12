#include<bits/stdc++.h>
using namespace std;
struct stu
{
	long long xuhao,score;
}stus[110];
bool cmp(stu stu1,stu stu2)
{
	return stu1.score>stu2.score;
}
long long n,m,k,rstn,rstm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		stus[i].xuhao=i;
		cin>>stus[i].score;
	}
	sort(stus+1,stus+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(stus[i].xuhao==1)
		{
			k=i;
			break;
		}
	}
	rstn=(k-1)/n+1;
	rstm=(k-1)%n+1;
	if(!(rstn%2))rstm=n-rstm+1;
	cout<<rstn<<' '<<rstm;
}
