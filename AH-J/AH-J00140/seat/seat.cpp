#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],seat;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>=a[1])seat++;
	}
	int l=seat/n,h=seat%n;
	if(h==0){
		if(l%2==0)printf("%d %d\n",l,1);
		else printf("%d %d\n",l,n);
	}
	else{
		if(l%2==0)printf("%d %d\n",l+1,h);
		else printf("%d %d\n",l+1,n-h+1);
	}
	return 0;
}
