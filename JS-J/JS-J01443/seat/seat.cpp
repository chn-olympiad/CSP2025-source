#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,sub[101],tmp,l,h;
	cin>>m>>n;
	for(int i=1;i<=(m*n);++i)cin>>sub[i];
	int t=sub[1];
	for(int i=1;i<m*n;++i)
	{
		for(int j=m*n;j>i;--j)
		{
			if(sub[j]>sub[j-1])swap(sub[j],sub[j-1]);
		}
		if(sub[i]==t)
		{
			tmp=i;break;
		}
	}
	l=ceil(tmp*1.0/m);
	if(l%2==1)h=tmp-m*(l-1);
	else h=m-tmp+m*(l-1)+1;
	cout<<l<<" "<<h<<endl;
	return 0;
}
