#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++){
		scanf("%d",&a[i]);
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	int k=lower_bound(a+1,a+1+n*m,s)-a-1;
	k=n*m-k;
	int y=k/n,x=0;
	int mod=k%n;
	if(mod)y++;
	else mod=n;
	if(y%2)x=mod;
	else x=n-mod+1;
	cout<<y<<" "<<x;
	return 0;
} 
