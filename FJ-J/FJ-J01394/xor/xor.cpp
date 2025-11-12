#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N];
long long ejz(int a){
	int i=1,sum;
	while(a!=0){
		sum+=a%2*i;
		i*=10;
		a/=2;
	}
	return sum;
} 
long long xr(long long m,long long n){
	int sum=m+n,i=10;
	while(1){
	    if(sum%i==sum)break;
		if(sum%i/(i/10)==2)sum-=2*(i/10);
		i*=10;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,flag;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	while(i<=n){
		for(int j=i;j<=n;j++){
			long long temp;
			if(a[j]==k){
				cnt++;
				continue;
			}
			temp=xr(ejz(temp),ejz(a[j]));
			if(temp==ejz(k)){
				cnt++;
				continue;
				if(i+j>n)break;
			}
			i+=j;
		}
	}
	cout<<cnt;
	return 0;
}
