#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,g,sum;
int a[N];
bool b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n;i++){
		if(a[i]!=1) b=1;
	}
	if(b==0&&k==0&&n<=2) g=n;
	printf("%d",g);
	return 0;
} 
