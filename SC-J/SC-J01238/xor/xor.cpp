#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500010],s[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	int o=0,sum=0;
	for(int l=1;l<=n;l++){
		sum=a[l];
		if(a[l]!=k){
			for(int r=l+1;r<=n;r++){
				if(a[r]!=k){
					sum=sum^a[r];
					if(sum==k){
						cnt++;
						sum=a[r]; 
						continue;
					}
				} else{
					l=r;
					break;
				}	
			}
		}	
	}
	cout<<cnt;
	return 0;
}