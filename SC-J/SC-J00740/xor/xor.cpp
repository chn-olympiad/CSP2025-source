#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],k,b[20],c[N][20],nxt[20][N];
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1&&a[i]!=0) f=1;
	}
	if(!f){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else{
					if(a[i]==a[i+1]&&a[i]==1){
						ans++;
						i++;
					}
				}
			}
			cout << ans;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout << ans;
		}
	}//else{
//		int cnt=0;
//		while(k){
//			b[cnt]=k%2;
//			k/=2;
//			cnt++;
//		}
//		for(int i=1;i<=n;i++){
//			int cnt=0;
//			while(a[i]){
//				c[i][cnt]=a[i]%2;
//				a[i]/=2;
//				cnt++;
//			}
//		}
//	}
	
	
	return 0;
}