#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,ro,temp;
/*int take(int b[5001],int k){
	for(int i=0;i<)
}*/
int max1(int a[5001],int t){
	if(t==1) return a[0];
	else return max(a[t-1],max1(a,t-1));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(n=3){
		if(max(a[0],max(a[1],a[2]))>(a[0]+a[1]+a[2])*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a[n-1]==1){
		for(int i=n;i>=3;i--){
			temp=1;
			for(int j=0;j<i;j++){
				temp*=i-j;
				temp%=998244353;
			}
			sum+=temp;
			sum%=998244353;
		}cout<<sum;
	}else{
		cout<<0;
	}
	return 0;
}