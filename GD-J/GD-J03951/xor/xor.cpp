#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,a[N],ans,bj[N],s;
struct stu{
	int x,y;
}w[N];
void f(int x,int y)
{
	int t=0;
	for(int i=x;i<=y;i++)
	{
		t=t^a[i];
	}
	if(t==k) 
	{
		w[++s]={x,y};
	}
}
bool cmp(stu x,stu y)
{
	if(x.y!=y.y) return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			f(j,j+i-1);
		}
	}
	sort(w+1,w+s+1,cmp);
	int r=w[1].y;
	for(int i=2;i<=s;i++)
	{
		if(r<w[i].x) ans++,r=w[i].y;
	}
	printf("%d",ans+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
