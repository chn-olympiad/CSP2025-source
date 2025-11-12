#include<bits/stdc++.h>
using namespace std;
int a[500010],x,maxn=0,sum1[500010],sum2[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	sum1[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum1[i]=sum1[i-1]^a[i];
	}
	sum2[n+1]=0;
	for(int i=n;i>=1;i--){
		sum2[i]=sum2[i+1]^a[i];
	}
	int l=1,x=0,y=n;
	while(x!=y){
		if(l==y){
			x++;
			y--;
			l=x;
		}
		
		if((sum1[l]^sum1[x])==k&&(sum2[l+1]^sum2[y])==k){
			maxn=max(abs(x-l),max(abs(y-l+1),maxn));
			l++;
		}else{
			l++;
		}
	}
	cout<<maxn;
	return 0;
}

