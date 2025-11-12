#include<bits/stdc++.h>
using namespace std;

struct Node{
	int l,r;
}b[500001];

long long k;
int n,top;
int a[500001];

bool calc(const Node &x,const Node &y){
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		long long x=a[i];
		if(x==k){
			b[++top].l=i;
			b[top].r=i;
		}else{
			for(int j=i+1;j<=n;j++){
				x^=a[j];
				if(x==k){
					b[++top].l=i;
					b[top].r=j;
				}
			}
		}
	}
	sort(b+1,b+top+1,calc);
	int ans=0,l=1;
	for(int i=1;i<=top;i++){
		if(b[i].l>=l){
			ans++;
			l=b[i].r+1;
		}
	}
	printf("%d",ans);
}
