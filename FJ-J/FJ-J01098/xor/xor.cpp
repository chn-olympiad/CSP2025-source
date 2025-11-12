#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int len=1; len<=n; len++){
		for(int l=1; l<=n-len+1; l++){
			int r=l+len-1;
			int x=0;
			bool fl=0;
			for(int i=l; i<=r; i++){
				if(f[i]){
					fl=1;
					break;
				}
				x=(x^a[i]);
			}
			if(fl)continue;
			if(x==k){
				for(int i=l; i<=r; i++)f[i]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
