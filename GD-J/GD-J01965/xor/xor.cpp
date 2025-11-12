#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5,K=2e6+5;

int n,k;
int a[N],b[K];
int cnt;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	
	memset(b,-1,sizeof(b));
	b[0]=0;
	int yh=0,dq=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		yh^=a[i];
		if(a[i]==k||b[yh^k]>=dq){
			cnt++;
			dq=i;
		}
		b[yh]=i;
	}
	
	printf("%d",cnt);
	return 0;
}
