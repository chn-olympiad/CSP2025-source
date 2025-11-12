#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt,num,maxd;
//int b[5005],t,maxd=-1e+5;
//void print()
//{
//	cnt++;
//	for(int i=1;i<=t;i++)
//		cout<<b[i]<<" ";
//	cout<<endl;
//	cout<<sum<<" "<<maxd<<endl;
//	maxd=-1e+5;
//}
//void seach(int x)
//{
//	sum++;
//	for(int i=x;i<=n;i++)
//	{
//		int tw=t;
//		b[++t]=a[i];
//		if(a[i]>maxd) maxd=a[i];
//		int num=0;
//		for(int j=1;j<=t;j++) num+=b[j];
//		if(sum>=3&&num>maxd*2) print();
//		else seach(i+1);
//		b[tw]=0; t--;
//	}
//	sum--;
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				num=a[j]+a[i]+a[k];
				maxd=max(a[k],a[j],a[i]);
				if(num>maxd*2) {cnt++;}
			}
	cout<<cnt%998244353<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

