#include<bits/stdc++.h>
using namespace std;
int m,n,a[10010],o,ansm=1,ansn,cnt=1;
bool p=1,k;
bool cmp(int s1,int s2)
{
	return s1>s2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+(m*n)+1,cmp);
	//for(int i=1;i<=m*n;i++)
	//{
		//cout<<a[i]<<" ";
	//}
	while(1)
	{
		k=0;
		if(!p)
		{
			for(int i=n;i>=1;i--)
			{
				if(a[cnt]==o)
				{
					ansn=i;
					k=1;
					break;
				}
				cnt++;
			}
			if(k!=1)
			{
				p=1;
				ansm++;
			}
		}else{
			for(int i=1;i<=n;i++)
			{
				if(a[cnt]==o)
				{
					ansn=i;
					k=1;
					break;
				}
				cnt++;
			}
			if(k!=1)
			{
				p=0;
				ansm++;
			}
		}
		if(ansn||cnt>=n*m)
		{
			break;
		}
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}
