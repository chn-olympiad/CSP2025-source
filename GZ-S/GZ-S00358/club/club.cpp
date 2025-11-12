//GZ-S00358 遵义航天高级中学 罗上
#include<fstream>
#include<algorithm>
using namespace std;
struct people
{
	int club1;
	int club2;
	int club3;

};
struct qu
{
	int ans,club1=0,club2=0,club3=0;
}q[100000][3];
int n2;
qu& max(int n,qu & a,qu & b,qu & c)
{
	if(n==1&&a.club1==n2)
	{
		return (b.ans>c.ans)?b:c;
	}
	if(n==2&&b.club2==n2)
	{
		return (a.ans>c.ans)?a:c;
	}
	if(n==3&&c.club3==n2)
	{
		return (b.ans>a.ans)?b:a;
	}
	return (b.ans>c.ans&&b.ans>a.ans)?b:((a.ans>c.ans)?a:c);
}
int main()
{
	std::ifstream cin("club2.in",std::ios::in);
	std::ofstream cout("club.out",std::ios::out);
	int N;
	cin>>N;
	int ans;
	int n;
	for(int I=0;I<N;I++)
	{
		cin>>n;
		people *p=new people[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].club1>>p[i].club2>>p[i].club3;
		}
		n2=n/2;
		q[0][0].ans=p[0].club1;
		q[0][0].club1=1;
		q[0][0].club2=0;
		q[0][0].club3=0;
		q[0][1].ans=p[0].club2;
		q[0][1].club1=0;
		q[0][1].club2=1;
		q[0][1].club3=0;
		q[0][2].ans=p[0].club3;
		q[0][2].club1=0;
		q[0][2].club2=0;
		q[0][2].club3=1;
		for(int i=1;i<n;i++)
		{
			qu a=max(1,q[i-1][0],q[i-1][1],q[i-1][2]);
			q[i][0].ans=p[i].club1+a.ans;
			q[i][0].club1=a.club1+1;
			q[i][0].club2=a.club2;
			q[i][0].club3=a.club3;
			a=max(2,q[i-1][0],q[i-1][1],q[i-1][2]);
			q[i][1].ans=p[i].club2+a.ans;
			q[i][1].club1=a.club1;
			q[i][1].club2=a.club2+1;
			q[i][1].club3=a.club3;
			a=max(3,q[i-1][0],q[i-1][1],q[i-1][2]);
			q[i][2].ans=p[i].club3+a.ans;
			q[i][2].club1=a.club1;
			q[i][2].club2=a.club2;
			q[i][2].club3=a.club3;
		}
		cout<<max(q[n-1][0].ans,max(q[n-1][1].ans,q[n-1][2].ans))<<'\n';
	}
	return 0;
}
