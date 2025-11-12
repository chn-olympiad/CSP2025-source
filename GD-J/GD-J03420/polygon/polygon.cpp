#include<bits/stdc++.h>
using namespace std;
long long n,p,maxn,sum,cnt;
long long a[10010];
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		for(int i=7;i<(1<<n);i++){
			p=i,maxn=sum=0;
			for(int j=1;p;j++){
				if(p&1){
					maxn=max(maxn,a[j]);
					sum+=a[j];
				}
				p=p>>1;
			}
			maxn=maxn<<1;
			if(sum>maxn) cnt=(cnt+1)%998244353;
		}
		cout<<cnt<<endl;
	}
	else{
		p=n*(n-1),sum=2;
		for(int i=3;i<=n;i++){
			sum=sum*i%998244353;
			p=p*(n-i+1)%998244353;
			cnt=(cnt+p/sum)%998244353;
			
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
