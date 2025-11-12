//code by 201012280925LSY
#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long T,n;
struct student
{
	long long x,y,z;
	long long maxx,maxn;
}a[N];
long long one[N],two[N],three[N],cnt[4];
long long answer;
bool cmp(long long x,long long y)
{
	return a[x].maxx-a[x].maxn>a[y].maxx-a[y].maxn;
}
bool cmpa(long long x,long long y)
{
	return a[x].x>a[y].x;
}
bool cmpb(long long x,long long y)
{
	return a[x].y>a[y].y;
}
bool cmpc(long long x,long long y)
{
	return a[x].z>a[y].z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=max(a[i].y,a[i].z))one[++cnt[1]]=i,a[i].maxn=max(a[i].y,a[i].z),a[i].maxx=a[i].x;
			else if(a[i].y>=max(a[i].x,a[i].z))two[++cnt[2]]=i,a[i].maxn=max(a[i].x,a[i].z),a[i].maxx=a[i].y;
			else three[++cnt[3]]=i,a[i].maxn=max(a[i].y,a[i].x),a[i].maxx=a[i].z;
		}
		answer=0;
		if(max(max(cnt[1],cnt[2]),cnt[3])<=n/2)
		{
			for(int i=1;i<=cnt[1];++i)answer+=a[one[i]].x;
			for(int i=1;i<=cnt[2];++i)answer+=a[two[i]].y;
			for(int i=1;i<=cnt[3];++i)answer+=a[three[i]].z;
			cout<<answer<<"\n";
			continue;
		}
		if(cnt[1]>n/2)
		{
			sort(one+1,one+cnt[1]+1,cmp);
			for(int i=1;i<=n/2;++i)answer+=a[one[i]].x;
			for(int i=n/2+1;i<=cnt[1];++i)
			{
				if(a[one[i]].y>a[one[i]].z)two[++cnt[2]]=one[i];
				else three[++cnt[3]]=one[i];
			}
			for(int i=1;i<=cnt[2];++i)answer+=a[two[i]].y;
			for(int i=1;i<=cnt[3];++i)answer+=a[three[i]].z;
			cout<<answer<<"\n";
			continue;
		}
		if(cnt[2]>n/2)
		{
			sort(two+1,two+cnt[2]+1,cmp);
			for(int i=1;i<=n/2;++i)answer+=a[two[i]].y;
			for(int i=n/2+1;i<=cnt[2];++i)
			{
				if(a[two[i]].x>a[two[i]].z)one[++cnt[1]]=two[i];
				else three[++cnt[3]]=two[i];
			}
			for(int i=1;i<=cnt[1];++i)answer+=a[one[i]].x;
			for(int i=1;i<=cnt[3];++i)answer+=a[three[i]].z;
			cout<<answer<<"\n";
			continue;
		}
		sort(three+1,three+cnt[3]+1,cmp);
		for(int i=1;i<=n/2;++i)answer+=a[three[i]].z;
		for(int i=n/2+1;i<=cnt[3];++i)
		{
			if(a[three[i]].x>a[three[i]].y)one[++cnt[1]]=three[i];
			else two[++cnt[2]]=three[i];
		}
		for(int i=1;i<=cnt[1];++i)answer+=a[one[i]].x;
		for(int i=1;i<=cnt[2];++i)answer+=a[two[i]].y;
		cout<<answer<<"\n";
		continue;
	}
	return 0;
}
