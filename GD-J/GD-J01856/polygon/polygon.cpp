#include<iostream>
#include<cstdio>
using namespace std;
const int N=-1e9;
int n;
int a[5005];
bool b[5005];
int ans;
void dfs(int bs,int yx,int h,int maxx,int ew) //边数，已选,和,maxx 
{
	if(bs==yx)
	{
		if(h>maxx*2)
			++ans;
		return;
	}
	for(int i=ew; i<=n; ++i)
	{
		if(b[i])
			continue;
		b[i]=true;
		dfs(bs,yx+1,h+a[i],max(maxx,a[i]),i+1);
		b[i]=false;
	} 
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=3; i<=n; ++i)
	{
		dfs(i,0,0,N,1);
	}
	printf("%d",ans);
	return 0;
}
