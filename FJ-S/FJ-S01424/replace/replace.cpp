#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s1,s2;
}a[200005],ques[200005];
int n,q,ans[200005],t[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	for(int i=1;i<=q;i++) cin>>ques[i].s1>>ques[i].s2;
	for(int i=1;i<=q;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			int x=ques[i].s1.find(a[j].s1);string y=ques[i].s1;int v=0;
			while(x!=-1)
			{
				v++;
				for(int k=0;k<a[j].s1.size();k++) y[x+k]=a[j].s2[k];
				t[v]=x;
				x=y.find(a[j].s1);
			}
			y=ques[i].s1;
			while(v)
			{
				y=ques[i].s1;
				for(int k=0;k<a[j].s1.size();k++) y[t[v]+k]=a[j].s2[k];
				if(y==ques[i].s2) 
				{
					ans[i]++;
					break;
				}
				v--;
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}
