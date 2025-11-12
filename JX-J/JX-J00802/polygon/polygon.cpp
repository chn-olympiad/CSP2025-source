#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,total=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			total+=a[j];
		}
		sort(a,a+i);
		if(total>2*a[i]) ans++;
	}
	printf("%d",ans+n);
	return 0;
}
