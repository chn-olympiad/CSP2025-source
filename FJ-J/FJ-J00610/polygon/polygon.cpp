#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,ans;
int a[maxn];

int zh(int x,int y){
	int sh=1;
	for(int i=y;i>=(y-x+1);i--){
		sh*=i%998244353;
	}
	int xi=1;
	for(int i=x;i>=1;i--){
		xi*=i%998244353;
	}
	int zhs=(sh/xi)%998244353;
	return zhs;
}

void hhh(int x,int y,int z){
	if(y<0) return;
	if(z<=0 && y>=0){
		ans--;
	}
	if(z<=0 || x<=0){
		return;
	}
	
	for(int p=x-1;p>=1;p--){
		hhh(p,y-a[p],z-1);		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=zh(i-1,j-1);
			ans%=998244353;
			if(a[n]!=1)hhh(j,a[j],i-1);
		}
	}
	cout<<ans;
	return 0;
} 
