#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],cnt;
bool check(int l,int r){
	if(r-l+1<3)
		return false;
	int sum=0,maxn=-1;
	for(int i=l;i<=r;i++)
		sum+=a[i];
	for(int i=l;i<=r;i++)
		maxn=max(maxn,a[i]);
	return sum>(2*maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
			if(check(i,j))
				cnt++;
	cout<<cnt;
	return 0;
}