#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int sco=a[1],pm=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(sco==a[i]){
			pm=n*m-i+1;
			break;
		}
	}
	int z=ceil(pm*1.0/n);
	int h=pm%n;
	if(z%2==0){
		if(h==0) h=1;
		else h=n-h+1;
	}
	else{
		if(h==0) h=n;
	}
	printf("%d %d",z,h);
	return 0;
}

