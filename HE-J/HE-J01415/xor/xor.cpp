#include <bits/stdc++.h>
using namespace std;
long long a[500050],b[500050];
long long n,k;
long long ans;
long long c[5];
bool d[500050];
int yihuo(int x,int y)
{
	//cout<<x<<y;
	int ansa=0;
	int cnt=0;
	for(int i=1;i<=500000;i++)d[i]=0;
	for(int j=1;;j++)
	{
	//if(cnt>=r-l+1)break;
//	cout<<b[l]<<b[r];
//	cout<<l<<"    "<<r<<endl;
	//cout<<d[2]<<d[3];
	//	cout<<cnt<<endl;
	//	cout<<r-l+1<<" ";
		for(int i=x;i<=y;i++)
		{
			if(b[i]==0&&d[i]==1)continue;
			c[b[i]%2]++;
			b[i]/=2;
			if(b[i]==0)cnt++,d[i]=1;
		}
		if(c[1]%2!=0)ansa+=pow(2,j-1);
		c[1]=0;
		if(cnt>=y-x+1)break;
	}
	return ansa;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],b[i]=a[i];
		if(a[i]==0)x++;
	}
	if(k==0){
		cout<<x;
		return 0;
	}
	int l=1,r=1;
//	int a=yihuo(2,3);
//	cout<<a;
	for(int i=1;i<=n;i++)
	{
		while(r<=n)
		{
			for(int i=1;i<=n;i++)b[i]=a[i];
			if(yihuo(l,r)==k)
			{
				ans++;
				r++;	
				l=r;
			//cout<<0;
			//	cout<<l<<" "<<r;
				break;
			}
			else r++;
		}
		
		if(l>=n)break;
		if(l!=r)l++,r=l;
	}
	cout<<ans;
	return 0;
}


