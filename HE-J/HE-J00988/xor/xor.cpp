#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int a[n+10],ans=0,sum=0;
	bool b[n+10]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			if(i==sum){
				sum++;
			}ans++;
			b[i]=1;
			bool ac=0;
			for(int j=sum;j<=i&&ac==0;j++){
				int sun=a[j];
				for(int w=j+1;w<=i&&ac==0;w++){
					if(b[w]!=1){
						sun=sun^w;
					if(sun==k){
						ans++;
						ac=1;
						continue;
					}
					}
				}
			}sum=i+1;
		}
	}cout<<ans<<endl;
	return 0;
}
