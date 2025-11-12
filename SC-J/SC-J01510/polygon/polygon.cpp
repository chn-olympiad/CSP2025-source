#include<bits/stdc++.h>
using namespace std;
const int vismod=998244353;
int n;
int a[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int f=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(int j=n-2;j>=1;j--){
			long long cnt=0;
			for(int i=1;i<=j;i++){
				cnt=(cnt+i)%vismod;
			}
			if(j!=n-2&&j!=1){
				cnt=cnt*2-1;
			}
			ans=(ans+cnt)%vismod;
		}
		cout<<ans%vismod<<endl;
	}else if(n<=3){
		if(n<3){
			cout<<0<<endl;
		}else{
			int maxn=-1;
			int visi;
			for(int i=0;i<n;i++){
				maxn=max(maxn,a[i]);
				visi+=a[i];
			}
			if(visi>2*maxn){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
		
	}else{
		for(int i=0;i<=n-2;i++){
			ans=(ans+i)%vismod;
		}
		cout<<ans%vismod<<endl;
	}
	return 0;
}