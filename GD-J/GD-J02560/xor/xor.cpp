#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[500002],b[500002];
map<lo,lo> p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=(a[i]^b[i-1]);
	}
	r=0;
	p[0]=1;
	for(i=1;i<=n;i++){
		if(p[m^b[i]]>r){
			ss++;
			r=i;
		}
		p[b[i]]=i+1;
	}
	printf("%lld",ss);
	return 0;
}

