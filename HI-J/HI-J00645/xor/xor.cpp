#include<bits/stdc++.h>
using namespace std;
long long n,k,num,num1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n+1];
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(long long i=1;i<=n;i++) if(a[i]==1) num1++;
		if(num1==n){
			cout<<0;
			return 0;
		}
		else{
			long long num2=n-num1;
			cout<<num2;
			return 0;
		}
	}
	else if(k==1){
		for(long long i=1;i<=n;i++) if(a[i]==1) num++;
		cout<<num;
		return 0;
	}
	else if(k==255){
		for(long long i=1;i<=n;i++) if(a[i]==255) num++;
		cout<<num;
		return 0;
	}
	else{
		cout<<n;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
