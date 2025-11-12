#include <bits/stdc++.h>
int a[5010];
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x=0,s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x+=a[i];
		s=max(s,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(x>s*2)cout<<1;
		else cout<<0;
		return 0;
	}else{
		int c=0;
		if(x>s*2){
			for(int i=1;i<=n;i++){
				if(a[i]==1)c++;
			}
			if(c==n){
				int v=2,ans=1;
				while(v==n){
					for(int i=1;i<=n-v;i++){
						ans+=i;
					}
					v++;
				}
				cout<<ans%998244353;
			}
		}
		else cout<<0;
	}
}
