#include<bits/stdc++.h>
using namespace std;
long long unsigned answer=0;
int n,x[5005];
void f(long long limit,long long sum,long long max_number,long long lr,long long now_lr){
	long long max_number_now;
	if(max_number>=x[limit]){
		max_number_now=max_number;
	}
	else{
		max_number_now=x[limit];
	}
	if(now_lr==lr){
		if(sum>max_number_now*2 && limit<=n-1){
			answer++;
		}
	}
	else{
		for(long long i=limit+1;i<n;i++){
			f(i,sum+x[i],max_number,lr,now_lr+1);
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x[i];
	}

	for(long long i=3;i<=n;i++){
		for(long long j=0;j<n-i+1;j++){
			f(j,x[j],x[j],i,1);
		}
	}
	cout<<answer%998%244%353;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
