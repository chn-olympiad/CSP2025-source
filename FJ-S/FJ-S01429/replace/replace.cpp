#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
struct node{
	string p,q;
}a[N];
int sum;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].q;
	}
	while(q--)
	{
		string c,d;
		cin>>c>>d;
		if(c.size()!=d.size())
		{
			cout<<"0"<<endl;
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<c.size();j++)
			{
				string e=c,f=d;
				int flag=0;
				for(int k=j;k<j+a[i].p.size();k++)
				{
					if(e[k]!=a[i].p[k-j])flag=1;
				}
				if(!flag)
				{
					for(int k=j;k<j+a[i].p.size();k++)
					{
						e[k]=a[i].q[k-j];
					}
					if(e==f)
						sum++;
				}
					
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}