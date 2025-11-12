#include<bits/stdc++.h>
using namespace std;
int n,k,ways=0;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		int yu=a[1]^a[2];
		if(yu==k){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int l=1,r=1;l<=r<=n;r++){
		ways=0;
		if(r==n){
			l++;
			r=l+1;
		}
		int sumk=a[l];
		for(int i=l+1;i<=r;i++){
			sumk+=sumk^a[i];
		}
		if(sumk==k){
			ways++;
			l=r+1;
			r=l+1;
		}
	}
	cout<<ways;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
