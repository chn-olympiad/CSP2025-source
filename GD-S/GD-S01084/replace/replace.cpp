#include<bits/stdc++.h>
using namespace std;
int n,m;
long long w;
string a[200005],b[200005],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(m--)
	{
		cin>>c>>d;
		w=0;
		for(int i=1;i<=n;i++)
		{
			long long f=c.find(a[i]);
			if(f!=-1)
			{
				int h=0;
				string t=c;
				for(int j=f;j<f+a[i].size();j++)
				{
					t[j]=b[i][h];
					h++;
				}
				if(t==d)w++;
			}
		}
		printf("%lld\n",w);
	}
	
	return 0;
}
