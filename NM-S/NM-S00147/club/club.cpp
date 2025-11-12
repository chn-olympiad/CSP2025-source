#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct STU{
	int b[3],ma;
}a[N];
bool cmp(STU x,STU y){
	return x.b[x.ma]>y.b[y.ma];
}
int sec(STU z){
	if(z.ma==0){
		if(z.b[1]>z.b[2]){
			return 1;
		}else{
			return 2;
		}
	}
	if(z.ma==1){
		if(z.b[0]>z.b[2]){
			return 0;
		}else{
			return 2;
		}
	}
	if(z.ma==2){
		if(z.b[1]>z.b[0]){
			return 1;
		}else{
			return 0;
		}
	}
}
int dp[N],num[3],vis[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i].b[j];
				if(a[i].b[j]>a[i].b[a[i].ma]){
					a[i].ma=j;
				}
			}
	    }
	    sort(a,a+n,cmp);
	    dp[0]=a[0].b[a[0].ma];
	    vis[0]=a[0].ma;
	    num[a[0].ma]++;
	    for(int i=1;i<=n;i++){

	    	if(num[a[i].ma]+1>n/2){
	    		int k=i;
	    		while(k--){
	    			if(vis[k]==a[i].ma){
	    				break;
					}
				}
			int x=sec(a[i]);
			int y=sec(a[k]);
			if(a[k].b[y]+a[i].b[a[i].ma]>a[k].b[a[i].ma]+a[i].b[x]){
				dp[i]=dp[i-1]-a[k].b[a[i].ma]+a[k].b[y]+a[i].b[a[i].ma];
				cout<<111;
				num[y]++;
				vis[k]=y;
			}else{
				dp[i]=dp[i-1]+a[i].b[x];
				num[x]++;
	            vis[i]=x;

			}

			}else{
			dp[i]=max(dp[i],dp[i-1]+a[i].b[a[i].ma]);
		    num[a[i].ma]++;
	        vis[i]=a[i].ma;
			}
		}
		cout<<dp[n]<<endl;
	}

	return 0;
}
