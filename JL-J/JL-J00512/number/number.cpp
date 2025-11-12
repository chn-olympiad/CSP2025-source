#include <bits/stdc++.h>
using namespace std;
#define n 1000000
char x[n];
char a[n];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0,tmp=0;
	for(int i=0;i<n;i++)
	{
			cin>>x[i];
			cnt++;
			if(x[i]>='0'&&x[i]<='9')
			{
				a[tmp]=x[i];
				tmp++;
			}
			
			
	}
	if(cnt==1) cout<<a[0];
	if(cnt==2)
	{
		if(tmp==1) cout<<a[0];
		else
		{
			if(a[0]>a[1]) cout<<a[0]<<a[1]<<endl;
			else cout<<a[1]<<a[0]<<endl;
		}
		
	}
	
	return 0;
}
