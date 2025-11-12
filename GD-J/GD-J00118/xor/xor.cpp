#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=1;
long long a[5000005],len;
struct node{
	int s,e;
}c[100000001];
bool cmp(node x,node y){
	return x.e<y.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			len++;
			c[len].s=i;
			c[len].e=i;
			continue;
		}
		long long b=a[i];
		for(long long j=i+1;j<=n;j++){
			b^=a[j];
			if(b==k){
				len++;
				c[len].s=i;
				c[len].e=j;
				break;
			}
		}
	}
	sort(c+1,c+1+len,cmp);
	long long t=c[1].e;
	for(long long i=1;i<=len;i++){
			if(c[i].s>t){
				ans++;
				t=c[i].e;
			}
	}
	printf("%d",ans);
	return 0;
}

