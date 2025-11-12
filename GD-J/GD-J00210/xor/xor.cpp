#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+6;
ll n,k,a[N],ans=0;
void work3(){
	for(ll len=1;len<=n;++len){
		for(ll i = 1;i+len-1<=n;++i){
			ll j = i+len-1;
			for(ll d = i;d <= j;++d){
				if(a[d]==-1){
					i=d+1;
					break;
				}
			}
			ll g=a[i];
			for(ll d = i+1;d<=j;++d){
				g=(g^a[d]);
			}
			if(g==k){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return ;
}
bool pd=0;
void work1(){
	if(k==0){
		cout << n/2 << endl;
	}
	else if(k==1){
		cout << n << endl;
	}
	else{
		cout << 0 << endl;
	}
	return ;
}
bool pd2=0;
void work2(){
	if(k==1){
		for(ll i = 1;i <= n;++i){
			if(a[i]+a[i+1]==1){
				ans++;
				i++;
			}
			else{
				if(a[i]==1){
					ans++;
				}
			}
		}
	}
	else if(k==0){
		for(ll i = 1;i <= n;++i){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}
			else{
				if(a[i]==0){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1;i <= n;++i){
		cin>>a[i];
		if(a[i]!=1){
			pd=1;
		}
		if(a[i]>1){
			pd2=1;
		}
	}
	if(pd==0){
		work1();
	}
	else if(pd2==0){
		work2();
	}
	else{
		work3();
	}
	
	return 0;
} 
