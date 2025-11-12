#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				int h=a[i]+a[j]+a[k];
				int mx=max({a[i],a[j],a[k]});
				if(h>2*mx)++ans;
			}
		}
	}
	cout<<ans;
	return 0;
}