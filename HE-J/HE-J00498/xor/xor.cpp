#include<bits/stdc++.h>
using namespace std;
long long n,k,ji,jii,jji,a[500005];
int cnt=0,vis[500005];
long long f(int x,int y){
	int cnt1=0,j=0,cnt2=1;
	while(x!=0||y!=0){
		ji++;
		if(x%2!=y%2){
			for(int i=1;i<=ji-1;i++){
				cnt2*=2;
			}
			cnt1+=cnt2;
		}
		x/=2;
		y/=2;
	}
	return cnt1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
	}
	ji=f(a[1],a[2]);
	jii=2;
	for(int i=3;i<=n;i++){
		if(vis[i]==0){
			ji=f(ji,a[3]);
		}else{
			if(ji!=k){
				
			}
		}
		
	}
	return 0;
} 
