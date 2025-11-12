#include<bits/stdc++.h>
using namespace std;
int n,m,ad,rt,rw,mc,mr,tt[105];
bool cmpd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	ad=n*m;
	for(int i=1;i<=ad;i++)
		scanf("%d",&tt[i]);
	rt=tt[1];
	sort(tt+1,tt+ad+1,cmpd);
	for(int i=1;i<=ad;i++)
		if(tt[i]==rt){
			rw=i;break;
		}
	mc=ceil(1.0*rw/n);
	if(mc%2==1)
		mr=(rw-1)%n+1;
	else
		mr=n+1-((rw-1)%n+1);
	printf("%d %d",mc,mr);
	return 0;
}
