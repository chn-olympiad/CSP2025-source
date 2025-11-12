#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10; 
int n,k,a[maxn],s[maxn];
int do_xor(int x,int y)
{
	int ans=0,i=0;
	while(x!=0||y!=0)
	{
		int k=x%2,l=y%2;
		x/=2,y/=2;
		if(k!=l)
		{
			ans+=pow(2,i); 
		}
		i+=1;
	}
	return ans;
}
struct qujian{
	int l,r;
}b[maxn],c[maxn];
bool cmp(qujian x,qujian y)
{
	if(x.l==y.l)
	{
		return x.r<y.r; 
	}
	else
	{
		return x.l<y.l;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			s[i]=a[i];
		}
		else
		{
			s[i]=do_xor(a[i],s[i-1]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j&&s[i]==k)
			{
				cnt+=1;
				b[cnt].l=1,b[cnt].r=j;
				continue;
			}
			else if(do_xor(s[i],s[j])==k&&i!=j)
			{
				cnt+=1;
				b[cnt].l=i+1,b[cnt].r=j;
			}
		}
	}
	sort(b+1,b+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<b[i].l<<" "<<b[i].r<<endl;
//	}
	int p=1;
	for(int i=1;i<=cnt;i++)
	{
		if(b[i].l==p)
		{
			c[p].l=b[i].l,c[p].r=b[i].r;
//			cout<<c[p].l<<" "<<c[p].r<<endl;
			p+=1;
		}
	}
	p-=1;
	int ANS=0; 
	for(int st=1;st<=p;st+=1)
	{
		int ans=0,br=0;
		for(int i=st;i<=p;i++)
		{
			if(c[i].l>br)
			{
				ans+=1;
				br=c[i].r;
//				cout<<c[i].l<<" "<<c[i].r<<endl;
			}
		}
//		cout<<endl;
		ANS=max(ans,ANS);
	}
	cout<<ANS<<endl;
	return 0;
}