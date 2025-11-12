#include<iostream>
#include<algorithm>
using namespace std;
const int N=5010;
const int mod=998244353;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a[i]);
	sort(a+1,a+1+n);	
	cout<<sum;
	return 0;
}