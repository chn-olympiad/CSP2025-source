#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,gs,b,ans;
long long k,a[N],psum[N];

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		psum[i]=psum[i-1]^a[i];
		if(a[i]==1) gs++;
		if(a[i]==0) b++;
	}
	
	if(gs==n){
		cout<<n/2;
		return 0;
	}
	if(gs+b==n){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1 && a[i-1]==1) ans++;
			}
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	int ll=1,rr=1;
	while(rr<=n){
		int t=rr;
		while(t>=ll){
			if((psum[rr]^psum[t-1])==k){
				ans++;
				ll=rr+1;
				break;
			}
			t--;	
		}
		rr++;
	}
	cout<<ans;
	
	return 0;
}
