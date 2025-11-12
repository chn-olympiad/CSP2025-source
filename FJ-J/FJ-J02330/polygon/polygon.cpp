#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5001],n,x,sum=0;
bool book[5001];
void dfs(int s,int t,int m,int last){
	if(t==x+1&&s>m*2)
	{
		sum++;
		sum%=998244353;
	}
	for(int i=last;i<=n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			dfs(s+a[i],t+1,max(m,a[i]),i);
			book[i]=0;
		}
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i=1;
	cin>>n;
	for(;i<=n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(i=3;i<=n;i++)
	{
		x=i;
		memset(book,0,sizeof(book));
		dfs(0,1,0,1);
	}
	cout<<sum;
	return 0;
}
