//3-xor-2
#include<bits/stdc++.h>
using namespace std;
int b[2600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<(1<<21)<<" "<<sizeof(b)/1e6;
	int n,k;
	int l=1,p=0;
	int cnt=0;
	scanf("%d %d",&n,&k);
	b[0]=1;
	for(int i=2;i<=n+1;i++){
		int x;
		scanf("%d",&x);
		if(x==k){
			cnt++;
			l=i;
			x^=p;
			p=x;
			b[x]=i;
			//cout<<i<<endl;
			continue;
		}
		x^=p;
		/*if(k==0&&b[x^k]>l){
			cnt++;
			//cout<<b[x^k]<<" "<<l<<" "<<i<<endl;
			l=i;
		}*/
		if(b[(x^k)]>=l){
			cnt++;
			//cout<<b[x^k]<<" "<<i<<" "<<l<<endl;
			l=i;
		}
		b[x]=i;
		p=x;
	}
	printf("%d",cnt);
	return 0;
}
