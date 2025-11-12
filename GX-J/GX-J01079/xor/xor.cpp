#include<bits/stdc++.h>
using namespace std;
int tou(int a[],long long n){
	int tmp=a[0];
	for(int i=1;i<n;i++){
		if(a[i]!=tmp)return -1;
		tmp=a[i];
	}
	return tmp;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	scanf("%lld %lld",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0 && tou(a,n)==1){
		ans+=n/2;
	}
	else{
		for(int i:a){
			if(i==k)ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
