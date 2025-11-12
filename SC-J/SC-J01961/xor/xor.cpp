#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
int ans;
int solve(int k,int n){
	if(k){
		int x,y;
		for(int i=0;i<n;i++){
			if(a[i]) y++;
			else x++;
			if(x&&y){
				ans++;
				x=0;
				y=0;
			}
		}
		return ans;
	}
	else{
		int x,y;
		for(int i=0;i<n;i++){
			if(a[i]) y++;
			else x++;
			if(x==2||y==2){
				ans++;
				x=0;
				y=0;
			}
		}
		return ans;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("lld",&a[i]);
		if(a[i]) s++;
	}
	if(k==0&&s==n){
		cout<<n/2;
		return 0;
	}
	else{
		solve(k,n);
		if(ans){
			cout<<ans;
			return 0;	
		}
		cout<<3;
	}
	return 0;
}