#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200002],l,r,t,f,e;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(a[i]!=0)l=1;
		if(a[i]>1)r=1;
		t+=(a[i]==1);
	}
	if(l==0)cout<<n;
	else if(r==0){
		 if(t>(n/2))cout<<t;
		 else {
			if(t%2==0){
			LL sum=0;
				for(LL i=1;i<=n;i++){
					if(f==0&&a[i]==1){
						f=i;
					}
					else if(e==0&&f!=0&&a[i]==1){
						sum+=i-f+1;
						f=0;e=0;
					}
				}
				cout<<max(n-t,n-sum);
			}
			else cout<<n-t;
		 }
	}
	else cout<<1;
	return 0;
}
