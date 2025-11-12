#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,b=1;
	char c=getchar();
	while(c<'0'||'9'<c)
	{
		if(c=='-') b=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cout<<read(); 
	return 0;
}
