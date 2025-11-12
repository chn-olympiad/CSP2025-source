#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define LL long long
using namespace std;
const int N=1e6+10;
LL k;
LL n;
LL p,q;
LL ans;
LL a[N],b[N],c[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)	scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		if(a[i]==k){	ans++,b[++p]=-1,c[++q]=i;continue;}
		if(a[i]!=0)	b[++p]=a[i];
	}
	b[++p]=-1,c[++q]=p,c[0]=0;
	for(int i=1;i<=q;i++){
		int sum=0;
		for(int r=c[i-1]+1;r<=c[i]-1;r++){
			sum^=b[r];
			if(sum==k)	ans++,sum=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
