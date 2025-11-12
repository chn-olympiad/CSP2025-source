#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,a[500005],s,vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			vis[i]=1;
			sum++;
		}else if(vis[i]==0){
			s=a[i];
			for(int j=1;j<=n-i;j++){
				if(vis[i+j]==0){
					s=(s|a[i+j]);
				if(s==k){
					vis[i]=1;
					vis[i+j]=1;
					sum++;
				}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}