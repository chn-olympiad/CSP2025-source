#include<bits/stdc++.h>
using namespace std;

char c;
int a[1000010],k=1;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)
	{
		if(c>='0'&&c<='9')
		{
			a[k]=c-'0';
			k++;
		}
	}
	sort(a+1,a+k,cmp);
	for(int i=1;i<k;i++) cout<<a[i];
	return 0;
}
