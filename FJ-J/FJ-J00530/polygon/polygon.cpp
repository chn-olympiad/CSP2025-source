#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N];
map<int,int> m[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		m[i][a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(auto j:m[i]){
			for(int k=i+1;k<=n;k++){
				m[k][a[k]+j.first]=(m[k][a[k]+j.first]+j.second)%MOD;
			}
//			cout<<i<<" "<<j.first<<" "<<m[i][j.first]<<endl;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto j:m[i]){
//			if(m[i-1].count(j.first)){
//				m[i][j.first]=(m[i][j.first]+m[i-1][j.first])%MOD;
//			}
//		}
//	}
	int ans=0;
	for(int i=3;i<=n;i++){
		for(auto j:m[i]){
			if(j.first<=a[i]*2)continue;
			ans=(ans+j.second)%MOD;
		}
	}
	cout<<ans;
}

