#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a;
long long num[200005];//Ç°×ººÍ 
bool f[200005];
int ans;
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		num[i]=a^num[i-1];
	}
	for(int lenn=1;lenn<=n;lenn++){
		for(int l=1,r=l+lenn-1;r<=n;l++,r++){
			
			long long x=num[r]^num[l-1];
			if(x==k){
				
				bool flag=0;
				for(int i=l;i<=r;i++){
					if(f[i]){
						l=i;
						r=l+lenn-1;
						flag=1;
						break;
					}
				}
				if(flag)continue;
				
				
				ans++;
				for(int i=l;i<=r;i++){
					f[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

