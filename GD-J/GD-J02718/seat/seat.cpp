#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x,w,f;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	  if(a[i]==x)
		w=i;
	if(w%n!=0)
	  f=1;
	if(((w/n)%2==1&&f==0)||((w/n)%2==0&&f==1))//ÆæÊýÁÐ 
	{
		if(f==0)
		  cout<<w/n<<" "<<n;
		else
		  cout<<w/n+1<<" "<<w%n;
	}
	else
	{
		if(f==0)
		  cout<<w/n<<" "<<"1";
		else
		  cout<<w/n+1<<" "<<n-(w%n)+1;
	}
	return 0;
}


