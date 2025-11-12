#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long a[n+10],pre[n+10];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[0]=0;
	pre[1]=a[1];
	for(long long i=2;i<=n;i++){
		pre[i]=pre[i-1] xor a[i];
//		cout<<pre[i]<<' ';
	}
	long long ans=0;
	bool vis[n+10];
	for(long long i=0;i<=n;i++)vis[i]=0;
	for(long long len=1;len<=n;len++){
		for(long long l=0;l+len<=n;l++){
			if(( pre[l+len] xor pre[l] )==k){
//				cout<<pre[l+len]<<' '<<pre[l]<<' ';
//				long long x=pre[l+len] xor pre[l];
//				cout<<x<<endl;
				bool flag=0;
				for(long long i=l+1;i<=l+len;i++){
					if(vis[i]==1){
						flag=1;
						break;
					}
				}
				if(flag==0){
					for(long long i=l+1;i<=l+len;i++)vis[i]=1;
//					l+=len-1;
					ans++;
//					len=0;
				}
			}
		}
	}
	cout<<ans;
}
