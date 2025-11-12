#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ad[500005],m,sum=0;
struct cld{
	ll l,r,len;
	bool is;
	cld():is(1){};
}cldv;
cld clda[500005];
bool ctm(cld a,cld b){
	if(a.l<b.r)
		if(a.r>=b.l)
			return 1;
	if(b.l<a.r)
		if(b.r>=a.l)
			return 1;
	return 0;
}
bool cmpdd(cld a,cld b){
	if(a.len<b.len)
		return 1;
	else if(a.len>b.len)
		return 0;
	else return a.l<=b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ad[0]=0;
	ad[1]=a[1];
	for(int i=2;i<=n;i++)
		ad[i]=a[i]^ad[i-1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if((ad[i]^ad[j])==k){
				cldv.l=j+1,cldv.r=i,cldv.len=i-j;
				clda[m]=cldv;
				m++;
			}
	for(int i=0;i<m-1;i++){
		if(clda[i].is==0)
			continue;
		for(int j=i+1;j<m;j++){
			if(clda[j].is==0)
				continue;
			if(ctm(clda[i],clda[j])){
				if(clda[i].len>clda[j].len)
					clda[i].is=0;
				else 
					clda[j].is=0;
			}
		}
	}
	sort(clda,clda+m,cmpdd);
	for(int i=0;i<m;i++)
		if(clda[i].is==1)
			sum++;
	printf("%lld\n",sum);
	return 0;
} 
