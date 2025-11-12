#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],p[500005][25],b[500005][25],c[1000005],g[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		while(t){
			p[i][g[i]]=t%2;
			b[i][g[i]]=p[i][g[i]];
			b[i][g[i]]=(b[i][g[i]]+b[i-1][g[i]]+1)%2;
			g[i]++;
			t/=2;
		}
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<g[i];j++){
			if(b[i][j])sum+=pow(2,j);
		}
		if(sum==k){
			c[i]=1;
			ans++;
		}
	}
	for(int k=0;k<=n;k++){
		for(int i=k+1;i<=n;i++){
			int f=1;
			for(int j=i-k;j<=i;j++){
				if(c[j]){
					f=0;
					break;
				}
			}
			if(f){
				int cnt=0;
				for(int j=0;j<g[i];j++){
					if(b[i][j]==b[i-k][j]){
						cnt+=pow(2,j);
					}
				}
				if(cnt==k){
					for(int j=1;j<=n;j++){
						c[j]=1;
					}
					ans++;
				}
			}
		}
	}cout<<ans;
	return 0;
}
