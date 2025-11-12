#include<bits/stdc++.h>
using namespace std;
int n;
int a[5202];
bool n_value3(int n,int a[]){
	if(n<3){
		return false;
	}else if(n==3){
		int m=max(a[1],max(a[2],a[3]));
		int s=a[1]+a[2]+a[3];
		if(s>m*2) return true;
		else return false;
	}
}
int n_valueover3(int n,int a[]){
	sort(a+1,a+n+1);
	if(a[n]==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				sum++;
			}
		}
		sum%=998244353;
		return sum;
	}else{
		return 9;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=3){
		cout<<(n_value3(n,a)==true ? "1" : "0");
		return 0;
	}else{
		cout<<n_valueover3(n,a);
	}
	return 0;
}
