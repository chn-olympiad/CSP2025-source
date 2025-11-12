#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e5+10;
long long a[N][10];
long long b[10];
long long k[N];
int n;
int T;
vector<int>gh1;
vector<int>gh2;
vector<int>gh3;
bool cmp(const int &x,const int &y)
{
	return k[x]>k[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			b[1]=a[i][1];
			b[2]=a[i][2];
			b[3]=a[i][3];
			sort(b+1,b+3+1);
			k[i]=b[3]-b[2];
		}
		long long cnt1=0;
		long long cnt2=0;
		long long cnt3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				cnt1+=a[i][1];
				gh1.push_back(i);
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				cnt2+=a[i][2];
				gh2.push_back(i);
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
			{
				cnt3+=a[i][3];
				gh3.push_back(i);
			}
		}
//		cout<<-1<<endl;
		sort(gh1.begin(),gh1.end(),cmp);
		sort(gh2.begin(),gh2.end(),cmp);
		sort(gh3.begin(),gh3.end(),cmp);
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
		long long ret=cnt1+cnt2+cnt3;
//		cout<<gh1.size()<<" "<<gh2.size()<<" "<<gh3.size();
		if(gh1.size()>n/2)
		{
//			cout<<-1<<endl;
			for(int i=gh1.size()-1;i>=n/2;i--)
			{
//				cout<<gh1[i]<<endl;
				ret-=k[gh1[i]];
			}
		}
		if(gh2.size()>n/2)
		{
			for(int i=gh2.size()-1;i>=n/2;i--)
			{
				ret-=k[gh2[i]];
			}
		}
		if(gh3.size()>n/2)
		{
			for(int i=gh3.size()-1;i>=n/2;i--)
			{
				ret-=k[gh3[i]];
			}
		}
		printf("%lld\n",ret);
		gh1.clear();
		gh2.clear();
		gh3.clear();
		memset(k,0,sizeof(k));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}
