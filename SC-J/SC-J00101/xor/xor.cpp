#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
void solve1(){
	cout<<n/2<<"\n";
}
void solve2(){
	if(k==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans<<"\n";	
	}else{
		long long ans=0;int l=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				l=0;
				ans++;
			}else{
				l++;
				if(l==2){
					ans++;
					l=0;
				}
			}
		}
		cout<<ans<<"\n";	
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;int x=1,y=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			x=0;
			if(a[i]>1)y=0;
		}
	}
	if(k==0&&x==1){
		solve1();
		return 0;
	}
	if((k==1||k==0)&&y==1){
		solve2();
		return 0;
	}
	return 0;
}