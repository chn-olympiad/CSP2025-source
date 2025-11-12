#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
bool vis[5000005],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
			vis[i]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int l=i,r=j;
			if(l==r&&a[l]==k&&vis[l]==0){
				sum++;
				break;
			}
			if(vis[l]==0&&vis[r]==0){
				for(int k=l;k<r;k++){
					if(vis[k]==1){
						flag=1;
					}
				}
				if(flag==0){
				for(int k=l;k<=r;k++){
				cnt+=a[k];
			}
			if(cnt%2==k){
				sum++;
				vis[l]=1;
				vis[r]=1;
			}
				}
			}
			flag=0;
		}
	}
	cout<<sum;
	
	
	
	
	
	
	
	
	return 0;
}
