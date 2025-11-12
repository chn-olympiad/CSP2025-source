#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[50005];
int maxx=INT_MIN;
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	else if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)
		{
			cout<<1;
			return 0;
		}
	}
	return 0;
}
