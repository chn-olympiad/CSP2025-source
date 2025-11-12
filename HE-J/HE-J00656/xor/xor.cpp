#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,k;

int pd=3;

int a[N];

bool use[N];

int s[N];

int ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pd=min(pd,a[i]);//if is 1 ,A; else is 0 ,B;
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]^a[i];
	}
//	for(int len=1;len<=n;len++){
//		for(int l=1,r=len;r<=n;l++,r++){
//			for(int k=l;k+1<=r;k++){
//				inc(ans,l,k);
//				inc(ans,k+1,r);
//			}	
//		}
//	}
	if(pd){
		if(k==0){
			cout<<n/2;
		}else{
			cout<<n;
		}
	}else{
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					use[i]=1;
					ans++;
				}else if(a[i]==a[i-1]){
					if(!use[i-1]){
						use[i-1]=use[i]=1;
						ans++;
					}
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}
	
	return 0;
}
