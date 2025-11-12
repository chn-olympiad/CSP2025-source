#include<bits/stdc++.h>
using namespace std;
int n,m,a,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=2,x;i<=n*m;i++){
		scanf("%d",&x);
		if(x>a)
			k++;
	}
	int l=k/n;
	if(k%n)
		l++;
	int h=k%n;
	if(!h)
		h=n;
	if(l&1)
		printf("%d %d",l,h);
	else
		printf("%d %d",l,n-h+1);
	return 0;
}