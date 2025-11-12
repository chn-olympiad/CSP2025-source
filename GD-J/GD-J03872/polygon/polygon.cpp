#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int md=998244353;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i+2<=n;i++){
		ans+=(i*i);
		ans%=md;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
