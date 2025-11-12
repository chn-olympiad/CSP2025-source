#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,ans,sum,k,i,j;
int a[5000009],vist[5000009];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	while(cnt!=n){
		cnt++;
		for(i=1;i<=n;i++){
			ans=a[i];
			for(j=i+1;j<=i+cnt-1;j++){
				ans=ans|a[j];
				if(vist[j]==1||vist[j-1]==1)
				break;
			}
			if(j==i+cnt){
				if(ans==k){
					sum++;
					for(int w=i;w<=i+cnt;w++)
					vist[w]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 