#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    scanf("%d" ,&n);
    int a[n+10];
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%d",a[1]*a[2]);
    return 0;
}
