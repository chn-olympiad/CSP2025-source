#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
int ans,n,k,a[N];
bool vis[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	int l=1,r=1,m=0;
	while(l<=n){
		while(r<=n&&!vis[l][r]){
			for(int i=1;i<=r;i++) vis[l][i]=1;
			m=m^a[r];
			if(m==k){
				ans++;
				//cout<<l<<" "<<r<<endl;
				break;
			}
			r++;
			
		}
		l++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i][i]&&a[i]==k) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
