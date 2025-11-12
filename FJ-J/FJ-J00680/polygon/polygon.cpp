#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum,maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	    sum+=a[i];
	    maxn=max(a[i],maxn);
	}
    if(sum>maxn*2){
       printf("1");
	}
	else printf("0");
	return 0;
}
