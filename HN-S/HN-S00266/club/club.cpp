#include<bits/stdc++.h>
using namespace std;
int n,t;
int c[5],a[5];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(c,0,sizeof(c));
		int maxn,maxi,maxs,maxj;
		for(int i=1;i<=n;i++){
			maxn=0;
			for(int j=1;j<=3;j++){
				cin>>a[j];
				if(maxn<a[j]){
					maxn=a[j];
					maxi=j;
				}
			}
			if(c[maxi]>=n/2){
				for(int k=1;k<=3;k++){
					if(k!=maxi){
						if(maxs<a[k]){
							maxs=a[k];
							maxj=k;
						}
					}
				}
				c[maxj]++;
				ans+=maxs;
				//cout<<1<<endl;
			}else{
				c[maxi]++;
				ans+=maxn;
				//cout<<2<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

