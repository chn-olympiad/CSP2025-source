#include<bits/stdc++.h>
using namespace std;
int n,a[5003],s;
void f(int k,int sum,int x,int big){
	if(k==0){
		if(sum>big*2) s++;
		s=s%998244353;
		return;
	}
	for(int i=x;i<=n;i++){
		f(k-1,sum+a[i],i+1,max(big,a[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=3;i<=n;i++){
		f(i,0,1,0);
	}
	printf("%d",s%998244353);
	return 0;
}
/*
                    .
                   .+.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
                  .+++.
              <<<<<<*>>>>>>
                   |^|
                   |^|
                   |^|
                   \_/
*/
