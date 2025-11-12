#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,cnt=0;
int a[5050];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])	cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(n==4)
	{
		for(int i=1;i<=2;++i)
			for(int j=i+1;j<=3;++j)
				for(int k=j+1;k<=4;++k)
					if(a[i]+a[j]>a[k])	cnt++;
		if((a[1]+a[2]+a[3]+a[4])>a[4]*2)	cnt++;
		cout<<cnt<<endl;
	}
	else if(n==5)
	{
		for(int i=1;i<=3;++i)
			for(int j=i+1;j<=4;++j)
				for(int k=j+1;k<=5;++k)
					if(a[i]+a[j]>a[k])	cnt++;
		for(int i=1;i<=2;++i)
			for(int j=i+1;j<=3;++j)
				for(int k=j+1;k<=4;++k)
					for(int l=k+1;l<=5;++l)
						if((a[i]+a[j]+a[k]+a[l])>2*a[l])	cnt++;
		if((a[1]+a[2]+a[3]+a[4]+a[5])>a[5]*2)	cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}