//GZ-S00252 毕节东辰实验学校 杜文豪
#include <bits/stdc++.h>
using namespace std;
int t;
int a;
struct noo
{
	int man;
	int num;
}uma[5];
struct no
{
	long long bes1,best2;
	long long nobes;
}stu[100861];
bool cmpp(noo o,noo p)
{
	return o.man>p.man;
}
bool cmp(no o,no p)
{
	return o.nobes>p.nobes;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		long long ans=0;
		cin>>a;
		for(int n=1;n<=a;n++)//第n个学生 
		{
			cin>>uma[1].man>>uma[2].man>>uma[3].man;
			uma[1].num=1;uma[2].num=2;uma[3].num=3;
			sort(uma+1,uma+4,cmpp);
			if(uma[1].man==uma[2].man)
			{
				stu[n].bes1=uma[1].num;
				stu[n].best2=uma[2].num;
				stu[n].nobes=0;
			}
			else
			{
				stu[n].bes1=uma[1].num;
				stu[n].best2=uma[2].num;
				stu[n].nobes=uma[1].man-uma[2].man;
			}
			ans+=uma[1].man;
		}
		sort(stu+1,stu+1+a,cmp);
		int nu1=0,nu2=0,nu3=0;
		int fla=0,dang=0;
		for(int n=1;n<=a;n++)
		{
			dang=n;
			if(nu1==a/2){
				fla=1;break;
			}
			if(nu2==a/2){
				fla=2;break;
			}
			if(nu3==a/2){
				fla=3;break;
			}
			if(stu[n].bes1==1) nu1++;
			if(stu[n].bes1==2) nu2++;
			if(stu[n].bes1==3) nu3++;
		}
		for(int n=dang;n<=a;n++)
		{
			if(stu[n].bes1==fla) ans-=stu[n].nobes;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
