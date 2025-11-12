#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b,ans=0;
bool f[500005];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,0,sizeof(f));
    cin>>n>>b;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(b==a[i]){
			ans++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		for(int j=i;j<=n;j++){
			if(f[j])break;
			long long te=0;
			for(int k=i;k<=j;k++){
				te^=a[k];
				if(te==b){
					ans++;
					for(int l=i;l<=j;l++){
						if(f[l]==1){
							ans--;
							break;
						}
						f[l]=1;
					}
					break;
				}
			}
		}
	}cout<<ans;
	return 0;
}
