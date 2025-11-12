#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],k;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int c=i/n+(i%n?1:0);
			int r=(c%2?(i-1)%n+1:n-(i-1)%n);
			printf("%d %d",c,r);
			return 0;
		}
	}
	return 0;
}
