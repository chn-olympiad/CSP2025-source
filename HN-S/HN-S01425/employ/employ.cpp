#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],a0,a1,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int x;
	cin>>x;
	while(x){
		int x1=x%10;
		if(x1==1){
			a1++;
		}else{
			a0++;
		}
		x/=10;
	}
	a[n+1]=10000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<(1<<n);i++){
		int lo=0,b0=0,b1=0,ans=0;
//		cout<<"\n"<<i<<' ';
		for(int j=n-1;j>=0;j--){
//			cout<<(i>>j&1)<<' ';
			if(((i>>j)&1)==0){
				if(a[n-j]<=lo){
					lo--;
				}
				lo++;
				b0++;
				
			}else{
				ans++;
				b1++;
				if(a[n-j]<=lo){
					ans--;
				}	
			}
		}
//		cout<<"lo:"<<lo<<" win:"<<ans<<" 0:"<<b0<<" 1:"<<b1<<' ';
		if(b0==a0&&b1==a1&&ans>=m){
			cnt++;
//			cout<<i<<' ';
		}
	}
	cout<<cnt;
	return 0;
}

