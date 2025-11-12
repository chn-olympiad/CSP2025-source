#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100005],ans=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	if(ans>=2*a[n])cnt++;
	cout<<cnt%N;
	return 0;
}
