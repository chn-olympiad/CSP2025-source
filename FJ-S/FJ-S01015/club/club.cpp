#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long  aa,bb,cc;
struct ll{
	long long a1,a2,a3,num;
	bool bo=0;
}a[201000],d[201000],b[201000],c[201000];
bool cb(long long x,long long y){
	return b[x].a1>=b[y].a1;
}
bool cc(long long x,long long y){
	return c[x].a1>=c[y].a1;
}
bool cd(long long x,long long y){
	return d[x].a1>=d[y].a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%lld",&t);
for(int pp=1;pp<=t;pp++){
    scanf("lld",&n);long long ans=0,aa=0,bb=0,cc=0;	
    for(int i=1;i<=n;i++){
    	scanf("%lld %lld %lld",&a[i].a1 ,&a[i].a2 ,&a[i].a3);
    	a[i].num=i;
    	b[i].num=i;b[i].a1=a[i].a1;
    	c[i].num=i;c[i].a1=a[i].a2;
    	d[i].num=i;d[i].a1=a[i].a3;
	}
	sort(b+1,b+1+n,cb);
	sort(c+1,c+1+n,cc);
	sort(d+1,d+1+n,cd);
	for(int i=1;i<=n;i++){
		if((b[i].a1>=c[b[i].num].a1||bb>=n/2)&&aa<n/2&&(cc>=n/2||b[i].a1>=d[b[i].num].a1)&&!a[b[i].num].bo){
			a[b[i].num].bo=1;ans+=b[i].a1;aa++;
		}
		else{
			if(bb<n/2&&(cc>=n/2||c[i].a1>=d[c[i].num].a1)&&!a[c[i].num].bo){
				a[c[i].num].bo=1;ans+=c[i].a1;bb++;			
			}
			else{
				
			    if(cc<n/2&&!a[d[i].num].bo){
				    a[d[i].num].bo=1;ans+=d[i].a1;cc++;			
			    }
			}
		}
	}
	printf("%lld\n",ans);
}
	return 0;
}
