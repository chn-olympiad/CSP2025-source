#include<iostream>
#include<algorithm>
using namespace std;
int a[5010],mod=998244353;
bool flag=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	sort(a+1,a+i,cmp);
	
	if(flag==0){
		long long ans=((n-1)*(n-2))/2;
		cout<<ans%mod;
		return 0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>a[3]*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
