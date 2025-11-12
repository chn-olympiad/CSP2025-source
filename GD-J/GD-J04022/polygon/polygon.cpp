#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],sum,ans,maxn;
long long t[100100];
void f(int s,int num,int d){
	if (d>num){
		long long maxnn=0,summ=0;
		for (int i=1;i<=d;i++){
			maxnn=max(maxnn,t[i]);
			summ+=t[i];
		}
	    if (summ>maxnn*2){
	    	ans++;
	    	ans=ans%998244353;
		}	
		return;
	}
	for (int i=s;i<=n;i++){
		t[d]=a[i];
		f(i+1,num,d+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if (n==3){
		sum=a[1]+a[2]+a[3];
		maxn=max(a[1],a[2]);
		maxn=max(maxn,a[3]);
		if (sum>maxn*2){
			printf("1");
		}else{
			printf("0");
		}
	}else{
		for (int i=1;i<=n;i++){
		    f(1,i,1);
		}
		printf("%lld",ans%998244353);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
