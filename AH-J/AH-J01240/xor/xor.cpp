#include <bits/stdc++.h>
using namespace std;
struct qujian{
	long long a,b;
}q[10000005];
bool cmp(qujian aa,qujian bb)
{
	if(aa.a!=bb.a)return aa.a<bb.a;
	if(aa.b!=bb.b)return aa.b<bb.b;
}
bool yihuohe(int l,int r)
{
	int sum=l^(l+1);
	for(long long i=l+2;i<=r;i++)
	{
		sum=sum^i;
	}
	//cout<<l<<" '<<r<<' ';
	//cout<<sum<<endl;
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	long long num=0;
	cin>>n>>k;
	long long a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++)
		{
			if(yihuohe(l,r)==k)
			{
				q[num].a=l;
				q[num].b=r;
				num++;
			}
		}
	}
	sort(q+1,q+1+num,cmp);
	int sum=0;
	for(int i=1;i<=n;)
	{
		int temp=i;
		for(int j=1;j<=num;j++)
		{
			if(i==q[j].a)
			{
				sum++;
				i=q[j].b;
			}
		}
		if(temp==i)i++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
