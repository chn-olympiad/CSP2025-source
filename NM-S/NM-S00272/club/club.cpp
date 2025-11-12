#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int max_p=-1;
const int MAXN=1e5+5;
struct people
{
	int w;
	int ha;
};
int a[MAXN],b[MAXN],c[MAXN];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k,int v,int z1,int z2,int z3)
{
	if(max(max(z1,z2),z3)>n/2)
	{
		return;
	}
	if(k>n)
	{
		max_p=max(max_p,v);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
			dfs(k+1,v+a[k],z1+1,z2,z3);
		else if(i==2)
			dfs(k+1,v+b[k],z1,z2+1,z3);
		else
			dfs(k+1,v+c[k],z1,z2,z3+1);
	}
}
int main()
{
	//freopen("club1.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		max_p=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<max(a[1],max(b[1],c[1]))<<endl;
		if(n==1e5)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				max_p+=a[i];
			}
			cout<<max_p;
		}
		if(n<=4)
			dfs(1,0,0,0,0);
		else
		{
			/*sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);*/
			int az=0,bz=0,cz=0;
			for(int i=1;i<=n;i++)
			{
				bool flag1=false,flag2=false;
				if(az+1<=n/2 && a[i]>b[i] && a[i]>c[i])
				{
					max_p+=a[i];
					az++;
					flag1=true;
				}
				if(bz+1<=n/2 && (b[i]>a[i] && b[i]>c[i] || flag1))
				{
					max_p+=b[i];
					bz++;
					flag1=true;
				}
				if(cz+1<=n/2 && c[i]>a[i] && c[i]>b[i] || flag2)
				{
					max_p+=c[i];
					cz++;
					flag2=true;
				}
			}
		}
		cout<<max_p<<endl;
	}
	
	return 0;
}
/*First:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
