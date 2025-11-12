//F
#include<bits/stdc++.h>
using namespace std;
int a[5005];
int f(int n){
	if(n==0||n==1) return 1;
	int ans=1;
	for(int i=n;i>=2;i--)  ans*=i;
	return ans;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		int a[n];
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<0;
		return 0;
	}if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(max(a,b),c)*2<(a+b+c)) cout<<1;
		else cout<<0; 
	}else{
		bool zt=1;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(a[i]!=1) zt=0;
		}if(zt==1){
			int ans=0;
			for(int i=3;i<=n;i++){
				ans+=((f(n)/f(n-i))/f(i));
				ans%=998244353;
			}cout<<ans;
		}
	}
	return 0; 
}
//!
//dif:green 
//91min 12pts
//147min 36pts
//score=100+100+10+36=246?
//see you again at 14:30
//luogu:1623332
