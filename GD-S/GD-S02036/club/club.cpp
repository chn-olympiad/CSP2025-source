#include<bits/stdc++.h>
using namespace std;
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=1e5+10;
int a[N][5],ch[N];
void work()
{
	int n=in();
	for(int i=1;i<=n;i++)ch[i]=0;
	int sum=0,cnt[5]={};
	for(int i=1;i<=n;i++)
	{
		a[i][1]=in(),a[i][2]=in(),a[i][3]=in();
		int u=1;
		if(a[i][2]>a[i][u])u=2;
		if(a[i][3]>a[i][u])u=3;
		cnt[u]++,sum+=a[i][u],ch[i]=u;
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)return out(sum),putchar('\n'),void();
	int p=1;
	if(cnt[2]>n/2)p=2;
	if(cnt[3]>n/2)p=3;
	vector<int>aa;
	for(int i=1;i<=n;i++)
	{
		int x=a[i][1],y=a[i][2];
		if(p==1)x=a[i][3];
		else if(p==2)y=a[i][3];
		if(ch[i]==p)aa.push_back(a[i][p]-max(x,y));
	}
	sort(aa.begin(),aa.end());
	int tot=cnt[p]-n/2;
	for(int i=0;i<tot;i++)sum-=aa[i];
	out(sum),putchar('\n');
}
int main()
{
//	system("fc club5.ans club.out");return 0;
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	for(int t=in();t--;work());
	return 0;
}
