#include<bits/stdc++.h>
using namespace std;
int a[5555],b[5555];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxa=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		b[i]=b[i-1]+a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int cnt=0,cnt1,cnt2;
	for(int i=n;i>=3;i--)
	{
		cnt1=0,cnt2=0;
		if(b[i]>=2*a[i])
		cnt2++;
		for(int j=1;j<i;j++)
		{
			if(b[i]-a[j]>2*a[i])
			cnt1++;
		}
		if(cnt1==0&&cnt2==0) continue;
		if(i-cnt1<3)
		{
			cnt+=cnt1*(cnt1-1)/2+cnt1;
		}
		else if(cnt!=0) cnt+=pow(2,cnt1);
		cnt+=cnt2;
	//	cout<<cnt1<<" "<<cnt2<<" "<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
}