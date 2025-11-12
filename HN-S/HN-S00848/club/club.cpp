#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100001];
int sum,s,ans,d,f;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n; 
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[k];
				if(sum<a[k]){
					sum=a[k];
					s=k;
				}
			}
			ans+=sum;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 

