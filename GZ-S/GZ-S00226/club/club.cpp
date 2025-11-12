#include<bits/stdc++.h>//GZ-S00226 贵阳剑桥学校(初中部) 李政轩 
using namespace std;
int t;
long long n,cnt;
const int maxn = 100001;
int a[3],b[3],te[3];
bool cmp(int a,int b)
{
	if(a>b)return true;
	else return false;
}
int find(int b)
{
	for(int i=1;i<=3;i++)
	{
		if(a[i] == b)return i;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k = 1;k<=3;k++)
			{
				te[k] = 0;
				scanf("%d",&a[k]);
				te[k]+=a[k];
			}
			sort(te+1,te+4,cmp);
			cnt+=te[1];
		}
		cout<<cnt<<endl;
		cnt = 0;
	}
	return 0;
}
