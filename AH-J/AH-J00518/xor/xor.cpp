#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    scanf("%d%d",&n,&k);
    int s=0
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
    for(int i=1;i<n;i++){
		int m=0;
		for(int j=i;j<=n;;j++){
			m^=a[j];
			if(m==k) s++;
		}
	}
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
