#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node
{
	int x,b,c,ms;
};
node a[N];
int va[N],vb[N],vc[N];

bool cmp1(int x,int y){ return a[x].x + a[y].ms < a[y].x + a[x].ms;}
bool cmp2(int x,int y){ return a[x].b + a[y].ms < a[y].b + a[x].ms;}
bool cmp3(int x,int y){ return a[x].c + a[y].ms < a[y].c + a[x].ms;}
int read()
{
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x;
 } 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read(),n;
	while(t--)
	{
		int l1 = 0,l2 = 0,l3 = 0;
		long long sum = 0;
		n = read();
		for(int i = 1 ; i <= n ; i++)
		{
			a[i].x = read(),a[i].b = read(),a[i].c = read();
			if(a[i].x >= a[i].b && a[i].x >= a[i].c)va[++l1] = i,sum += a[i].x,a[i].ms = max(a[i].b,a[i].c);
			else if(a[i].b >= a[i].x && a[i].b >= a[i].c)vb[++l2] = i,sum += a[i].b,a[i].ms = max(a[i].x,a[i].c);
			else if(a[i].c >= a[i].x && a[i].c >= a[i].b)vc[++l3] = i,sum += a[i].c,a[i].ms = max(a[i].b,a[i].x);
		}
		sort(va + 1,va + l1 + 1,cmp1),sort(vb + 1,vb + l2 + 1,cmp2),sort(vc + 1,vc + l3 + 1,cmp3);
		if(l1 > n / 2)for(int i = 1 ; i <= l1 - n / 2 ; i++)sum += a[va[i]].ms - a[va[i]].x; 
		if(l2 > n / 2)for(int i = 1 ; i <= l2 - n / 2 ; i++)sum += a[vb[i]].ms - a[vb[i]].b; 
		if(l3 > n / 2)for(int i = 1 ; i <= l3 - n / 2 ; i++)sum += a[vc[i]].ms - a[vc[i]].c; 
		cout<<sum<<endl;
	}
	return 0;
 } 
