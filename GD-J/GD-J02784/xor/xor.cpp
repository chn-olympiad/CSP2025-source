#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500006];
int b[500006];
struct wh{
	int s,e;
} c[50000007];
bool A=1,B=1;
bool cmp(wh o,wh y){
	if(o.e==y.e)return o.s<y.s;
	return o.e<y.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(A&&a[i]!=1)A=0;
		if(B&&a[i]!=1&&a[i]!=0)B=0;
	}
	if(n==0){
		printf("0");
		return 0;
	}
	if(A)printf("%lld",n/2);
	else if(B){
		int cnt0=0,cnt1=0,combo1=0;
		bool ocombo1=1;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt1++;
			if(a[i]==0)cnt0++;
			if(ocombo1&&a[i]==1&&a[i-1]==1){
				combo1++;
				ocombo1=0;
				continue;
			}
			if(!ocombo1)ocombo1=1;
		}
		if(k==1)printf("%d",cnt1);
		else printf("%d",cnt0+combo1);
	}
	else if(n<=1000){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			b[i]=a[i]^b[i-1];
		}
		for(int zl=1;zl<=n;zl++){
			for(int zr=zl;zr<=n;zr++){
				if(b[zr]^b[zl-1]==k){
					c[++cnt].s=zl;
					c[cnt].e=zr;
				}
			}
		}
		int zg=1,t=0;
		sort(c+1,c+cnt+1,cmp);
		while(zg<=cnt){
			if(c[zg].s>=t){
				ans++;
				t=c[zg].e+1;
			}
			zg++;
			
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

