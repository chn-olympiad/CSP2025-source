#include<bits/stdc++.h>
using namespace std;
int n,k,ans1,ans;
int arr[500050],vis[500050],sumz[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];	
		if(arr[i]==k){
			vis[i]=1;
			ans++;
		}
	} 
	if(k<=1){
		int cnt1=0;
		for(int i=0;i<n;i++){
			cnt1=0;
			int sum=0;
			for(int j=i;j<n;j++){
				cnt1++;
				vis[i]=1;
				if(arr[j]^sum==k){
					ans1++;
					break;
				}
			}
			i+=cnt1-1;
		}
		cout<<ans1;
		
		return 0;
	}
	/*while(true){
		bool z=false;
		for(int i=0;i<n;i++){
			if(vis[i]!=1){
				z=true;
				int cnt=0;
				memset(sumz,0,zizeof(sumz));
				sumz[++cnt]=arr[i];
				for(int j=i+1;j<=n;j++){
					sumz[++cnt]=sumz[cnt-1]^arr[i];
					for(int s=2;s<cnt;s++){
						if(sumz[s]^k==sumz[cnt]){
							vis[i]=1;
							break;
						}
					}
				}
			}
		}
		if(!z) break;
	}*/
	
	return 0;
}
