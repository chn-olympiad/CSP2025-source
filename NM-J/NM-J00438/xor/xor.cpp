#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long n(0),k(0);
	scanf("%d %d",&n,&k);
	vector<int> x(n+1);
	for(long i=1;i<=n;i++){
		long t=0;
		scanf("%ld",&t);
		x[i]=t;
	}
	long co=0;
	for(long i=1;i<=n;i++){
		for(long j=1;j<=n;j++){
			long qu=x[i];
			long he=0;
			for(long t=i;t<=j;t++){
				long l=x[t];
				qu=qu^l;
				if(qu==k){
				co++;
				}
			}
			
		}
	}
	cout<<co;
	return 0;
}

