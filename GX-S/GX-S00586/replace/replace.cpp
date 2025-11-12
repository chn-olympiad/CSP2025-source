#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,q,maxx=-99999999,minn=99999999;
string s1[100010],s2[100010],t1[100010],t2[100010];
struct nx
{
	int len,dis,p;
}a[100010];
nx b[100010];
string read()
{
	char c=getchar();
	string s;
	while(!(c>='a'&&c<='z')) c=getchar();
	while(c>='a'&&c<='z') s+=c;
	return s;
}
bool cmp(nx a1,nx a2)
{
	return a1.dis,a2.dis;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    	s1[i]=read(),s2[i]=read();
    for(int i=1;i<=q;i++)
    	t1[i]=read(),t2[i]=read();
    for(int i=1;i<=n;i++)
    {
        a[i].len=s1[i].size();
        for(int j=0;j<a[i].len;j++)
        	if(s1[i][j]=='b') {a[i].p=j+1;break;}
        for(int j=0;j<a[i].len;j++)
        	if(s2[i][j]=='b') {a[i].dis=a[i].p-(j+1);maxx=max(maxx,a[i].dis);minn=min(minn,a[i].dis);break;}
    }
    for(int i=1;i<=q;i++)
    {
        b[i].len=t1[i].size();
        for(int j=0;j<b[i].len;j++)
        	if(t1[i][j]=='b') {b[i].p=j+1;break;}
        for(int j=0;j<b[i].len;j++)
        	if(t2[i][j]=='b') {b[i].dis=b[i].p-(j+1);maxx=max(maxx,b[i].dis);minn=min(minn,b[i].dis);break;}
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=q;i++)
    {
        int l=1,r=n,ans=b[i].dis,num=0;
        while(l<=r)
        {
        	int mid=l+r>>1;
        	if(a[mid].dis<ans) l=mid+1;
        	if(a[mid].dis>ans) r=mid-1;
        	if(a[mid].dis==ans)
        	{
        		for(int j=mid;a[j].dis==ans;j++)
        		{
                    if(a[j].p<=b[i].p&&a[j].len-a[j].p<=b[i].len-b[i].p) num++;
        		}
        		for(int j=mid-1;a[j].dis==ans;j--)
        		{
                    if(a[j].p<=b[i].p&&a[j].len-a[j].p<=b[i].len-b[i].p) num++;
        		}
        	}
        }
        cout<<num<<endl;
    }

    
	return 0;
}