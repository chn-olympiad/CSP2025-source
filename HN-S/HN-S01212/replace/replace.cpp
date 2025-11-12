#include<bits/stdc++.h>
using namespace std;

int n,k;

unordered_map<int,int> ump;

int read()
{
	bool stsv = true;
	int i=0;
	char t = getchar();
	while(t < 'a' || t > 'z')	t=getchar();
	while('a' <= t && t <= 'z')
	{
		if(t == 'b')
		{
			stsv = false;
		}
		t=getchar();
		if(stsv)	i++;
	}
	return i;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x1,x2;
		x1=read();
		x2=read();
//		cout<<x1<<' '<<x2<<endl;
		ump[x1-x2]++;
	}
	while(k--)
	{
		int x1,x2;
		x1=read();x2=read();
//		cout<<x1<<' '<<x2<<endl;
		cout<<ump[x1-x2]<<endl;
	}
	
	return 0;
}
