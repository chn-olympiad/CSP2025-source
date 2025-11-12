#include<bits/stdc++.h>
using namespace std;
int a[1005000];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int maxn=-1,sum=0;
	for(int i=1; i<=n; i++) {
		if(a[i]>maxn)maxn=a[i];
		sum+=a[i];
	}
	if(n==3&&(sum>(2*maxn)))cout<<1;
	else if(n==3&&(sum<=(2*maxn)))cout<<0;
	else if(n<3)cout<<0;
	else if(maxn==1)cout<<n-2;
	return 0;
}
