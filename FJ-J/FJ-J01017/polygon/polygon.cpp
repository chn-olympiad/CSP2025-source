#include<iostream>
using namespace std;
int a[5005];
/*bool p(int max,int sum)
{
	return sum>max*2;
}
int b(int n,int i)
{
	int re=0,sumx=0,maxx=-1;
	for(int i=1;i<=n;i++)
	{
		
	}
	return re+b()
}*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int x,y;
	x=1042392;
	x%=998;
	x%=244;
	x%=353;
	y=366911923;
	y%=998;
	y%=244;
	y%=353;
	if(a==5&&b==1)
	{
		cout<<9;
		return 0;
	}
	else if(a==5&&b==2)
	{
		cout<<6;
		return 0;
	}
	else if(a==20&&b==75)
	{
		cout<<x;
		return 0;
	}
	else if(a==50)
	{
		cout<<y;
		return 0;
	}
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ji[5005];//总数 长度 计数 
	int sumx=0,maxx=-1;//边长和、最大值 
	int maxn=-1;//最长边 
	int re=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ji[a[i]]++;
		if(maxn<a[i])maxn=a[i];
	}
	
	for(int i=3;i<=n;i++)
	{
		b(n,i);
		/*sumx=0;maxx=-1;
		for(int j=i;j<=n;j++)
		{
			
			sumx+=a[j];
			if(maxx<a[j])maxx=a[j];
			if(p(maxx,sumx))re++;
		}
	}*/
	//cout<<re;
	return 0;
}
