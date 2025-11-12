#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],vis[1010][1010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		int maxxx=-1;
		for(int i=1;i<=n;i++){
			maxxx=max(maxxx,a[i]);
		}
		if(2*maxxx<a[1]+a[2]+a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		int ans=0;
		for(int m=3;m<=n;m++){
			for(int l=1;l<=n;l++){
				for(int r=l+m-1;r<=n;r++){
					int sum=0,maxx=-1;
					for(int k=l;k<=r;k++){
						sum+=a[k];
						maxx=max(maxx,a[k]);
					}
					if(maxx*2<sum){
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
