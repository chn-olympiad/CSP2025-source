#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[1000001];
bool cmp(lo x,lo y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	k=n*m;
	for(i=1;i<=k;i++){
		scanf("%lld",&a[i]);
	}
	mm=a[1];
	sort(a+1,a+k+1,cmp);
	for(i=1;i<=k;i++){
		if(a[i]==mm){
			l=i;
			break;
		}
	}
	s=(l-1)/n+1;
	ss=(l-1)%n+1;
	if(!(s&1)){
		ss=n+1-ss;
	}
	printf("%lld %lld",s,ss);
	return 0;
}

