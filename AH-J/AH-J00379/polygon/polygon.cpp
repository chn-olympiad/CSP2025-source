#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=1e5+5;
int n,a[N];
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%d",&n);
	int s=0,maxn=0;
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]),s+=a[i],maxn=max(maxn,a[i]);
	//sort (a+1,a+n+1);
	if (s>maxn*2) printf ("%d\n",1);
	else printf ("%d\n",0);
	return 0;
}
