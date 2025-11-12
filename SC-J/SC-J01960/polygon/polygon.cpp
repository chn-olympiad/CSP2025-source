#include<bits/stdc++.h>
using namespace std;
bool comp(const int &a,const int &b){
	return a>b;
}
long long pp(int x){
	long long sum=0;
	sum=1;
	for(int i=x;i>0;i--){
		sum*=2;
		sum=(sum%998244353);
	}
	sum-=x+x*(x-1)/2+1;
	if(sum<0){
		sum+=998244353;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001],i;bool flag=1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	sort(a,a+n,comp);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[0]<=a[1]+a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(flag){
		cout<<pp(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}