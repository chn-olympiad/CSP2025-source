#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],qian[500005],dist[500005],f[500005],lin;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qian[i]=(qian[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dist[i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((qian[i]^qian[j-1])==k){
				dist[i]=j;
				break;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		if(dist[i]!=-1){
			lin=-1;
			for(int j=0;j<=dist[i]-1;j++){
				lin=max(lin,f[j]);
			}
			f[i]=lin+1;
		}
	}
	lin=-1;
	for(int i=1;i<=n;i++){
		lin=max(lin,f[i]);
	}
	cout<<lin;
	return 0;
}