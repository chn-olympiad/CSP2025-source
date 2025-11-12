#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[105],pos,pos1,pos2;
inline int read()
{
	char ch;
	int s=0,f=1;
	ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
bool cmp(int a,int b)
{
	if (a>b) return 1;
	else return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	//scanf("%d%d",&n,&m);
	//cout<<n<<endl<<m<<endl;
	scanf("%d",&a[1]);
	t=a[1];
	for (int i=2;i<=n*m;i++)
	a[i]=read();
	sort(a+1,a+1+n*m,cmp);
	//for (int i=1;i<=n*m;i++)
	//cout<<a[i]<<' ';
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==t) 
		{
			pos=i;
			break;
		}
	}
	pos1=pos/n;
	if (pos1*n<pos) pos1++;
	pos2=pos%n;
	if (pos1%2==1)
	{
		if (pos2==0) pos2=n;
	}
	else
	{
		if (pos2==0) pos2=1;
		else
		pos2=n-pos2+1;
	}
	cout<<pos1<<' '<<pos2;
	return 0;
}
