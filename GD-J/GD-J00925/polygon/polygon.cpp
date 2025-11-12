#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],tum[5000005],rum[5000005],plo,lop,opl;
string l[1500005],rt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l[1]="0";
	l[2]="1";
	tum[2]=a[1];
	rum[2]=1;
	plo=2;
	for(int i=2;i<=n;i++)
	{
		opl=plo;
		for(int j=1;j<=opl;j++)
		{
			rt=l[j]+'1';
			plo++;
			l[plo]=rt;
			tum[plo]=tum[j]+a[i];
			rum[plo]=rum[j]+1;
			l[j]=l[j]+'0';
			if(tum[j]>a[i]&&rum[j]>=2)
			{
				lop++;
			}
		}
	}
	cout<<lop;
	
	return 0;
}
