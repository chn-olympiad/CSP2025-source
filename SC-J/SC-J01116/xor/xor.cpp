#include<bits/stdc++.h> 
using namespace std;
//long long n,a[500005],k,ans,cnt;
//long long yh(long long l,long long r){
//	long long s=0;
//	for(int i=l;i<=r;i++){
//		s=s^i;
//	}
//}
//void dfs(int p){
//	if(p==n){
//		ans=max(ans,cnt);
//	}
//	for(int i=p+1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(yh(i,j)==k){
//				cout<<i<<" "<<j<<"\n";
//				cnt++;
//			}
//			dfs(j+1);
//		}
//	}
//	
//}
long long n,k,a[500005],p1,p0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			p1++;
		}
		if(a[i]==0){
			p0++;
		}
	}
	if(p1+p0==n){
		if(p1==n){
			if(k==0){
				cout<<n/2;
				return 0;
			}
		}else{
			if(k==1){
				cout<<p1;
			}else{
				long long s=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1&&a[i+1]==1){
						s++;
						i++;
					}
				}
				cout<<p0+s;
			}
		}
	}
	
	
	return 0;
}