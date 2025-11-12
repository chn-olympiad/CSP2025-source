#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);	
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		int cnt=0;
		for(int i=3;i<=n;i++){
			int sum=1;
			for(int j=1;j<=i;j++){
				sum*=(n+1-i)/i;
			}
			cnt+=sum;
		}
		cout<<cnt;
	}
	if(ans<=a[1]*2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		cout<<1;
		return 0;	
	}
	
	return 0;
}
