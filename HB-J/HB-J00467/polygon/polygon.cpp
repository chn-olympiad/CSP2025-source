#include<cstdio>
using namespace std;
int n,a[1000],o=0,p;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i+1]!=a[i]){
			p=a[i]*i;
			if(p>o)o=p;
		}
		else i++;
	}
	return 0;
	}
