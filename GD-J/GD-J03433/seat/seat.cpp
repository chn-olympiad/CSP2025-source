#include<bits/stdc++.h>
using namespace std;
int n,m,q[110],p=1,l,h,tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&q[i]);
		if(q[1]<q[i]) p++;
	}
	if(p%n==0)l=p/n;
	else l=p/n+1;
	tmp=(l-1)*n;
	if(l%2==0){
		h=(n+tmp-p+1);
	}
	else{
		h=(p-tmp);
	}
	cout<<l<<" "<<h;
	return 0;
}

