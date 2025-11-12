#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e6+5;
int a[N];
int t;
int ans=0;
int cnt=0;
int k;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	k=1;
	t=1;
	for(int i=1;i<=n;i)
	{
		ans=a[i];
		t++;
		ans+=a[++k];
		if(t>=3&&ans>a[n]*2){
			cnt++;
			k=i+1;
			t=0;
			i++;
		}
	}
    printf("%d",cnt);
    fclose(stdin);
	fclose(stdout);
	return 0;
}
