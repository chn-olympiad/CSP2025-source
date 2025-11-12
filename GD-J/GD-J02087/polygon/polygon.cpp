#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],qzh[1000005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	for(long long i=3;i<=n;i++)
	{
		long long genshu=i-1;
		for(long long j=i;j<=n;j++)
			for(long long k=1;k<=j-genshu;k++)
				if(a[k]+(qzh[j]-qzh[j-genshu])>a[j]*2)
					ans++;
	}
	cout<<ans;
	return 0;
}

