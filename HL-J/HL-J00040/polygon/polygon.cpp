#include<bits/stdc++.h>
using namespace std;
int a[5001];
int n;
int f(int m,int u,int t,int mx){
	if(u<3&&3-u>n-m){
		return 0;
	}
	if(m==n){
		if(u>=3){
			if(t>mx*2){
				return 1;
			}
		}
		return 0;
	}
	return f(m+1,u+1,t+a[m+1],max(mx,a[m+1]))+f(m+1,u,t,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
//	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>max(max(a[1],a[2]),a[3])*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
//	if(n>20&&maxn==1){
//		unsigned long long sum=1;
//		for(int i=n;i>3;i--){
//			sum*=i;
//		}
//		cout<<sum/(n-3);
//	}
//	cout<<f(1,1,a[1],a[1])+f(1,0,0,0);
	cout<<f(0,0,0,0);
	return 0;
}
