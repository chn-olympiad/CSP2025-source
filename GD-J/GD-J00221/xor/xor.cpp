#include<bits/stdc++.h>
using namespace std;
long long n,k,arr[500010],cnt[500010],ans,sum,f[500010],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<n;i++) cnt[i]=arr[i]^arr[i+1];
	for(int i=1;i<=n;i++){
		if (arr[i]==k){
			ans++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		sum=0;
		flag=0;
		long long l,r;
		if(i==1){
			l=1,r=1;
		}
		else l=i+2,r=i+2;
		while(sum<k&&r<=n){
			if(sum==0&&f[r+1]==0&&f[r]==0) sum=cnt[r];
			else if(f[r+1]==0&&f[r]==0)sum=sum^cnt[r];
			r++;
			if(sum==k){
				for(int j=l;j<r;j++) f[j]=1;
				ans++;
				break;
			}
		}
		i=r;
	}
	cout<<ans;
	return 0;
}
