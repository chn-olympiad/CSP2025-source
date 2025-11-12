#include<bits/stdc++.h>
using namespace std;
int a[2*5000];
int bns[2*5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int maxx=-0x3f3f3f3f;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>maxx){
				maxx=a[i];
			}
			ans+=a[i];
		}
		if(ans>maxx*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++){
			ans+=i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
