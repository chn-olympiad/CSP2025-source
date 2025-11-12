#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],res,k,rn,rm;
bool cmp(int x,int y){return x>y;}
int up(int x,int y){
	if(x%y==0) return x/y;
	return x/y+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",a+i);
	res=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==res){
			k=i;
			break;
		}
	}
	rm=up(k,n);
	rn=(k-1)%(2*n)+1;
	if(rn>n) rn=2*n-rn+1;
	cout<<rm<<" "<<rn;
	return 0;
}
