#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a[i]);
    sort(a+1,a+n+1);
    int s=0;
    if(n==3&&a[1]+a[2]>a[3]){
		printf("1");
	}
    return 0;
}
