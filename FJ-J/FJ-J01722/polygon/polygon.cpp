#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;typedef int t;typedef long long ll;
t n,a[5086],d,s,b,ass;
t main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(t i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d",ass);
	return 0;
}
