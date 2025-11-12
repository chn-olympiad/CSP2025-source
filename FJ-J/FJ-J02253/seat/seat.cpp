#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int t=a[1],id=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			id=n*m-i+1;
			break;
		}
	}int l=int((id-1)/n+1);
	if(l%2==1) printf("%d %d",l,(id-1)%n+1);
	else printf("%d %d",l,n-(id-1)%n);
	return 0;
}
