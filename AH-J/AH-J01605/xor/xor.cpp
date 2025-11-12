#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],ans,l=1;
bool vis[N];
void fun(int l,int r){
	for (int i=l;i<=r;i++){
		for (int j=2;j<=r-i+1;j++){
			if ((sum[i+j-1]^sum[i-1])==k){
				bool f=0;
				for (int k=i;k<=i+j-1;k++){
					if (vis[k]){
						f=1;
						for (int o=i;o<k;o++) vis[o]=0;
						break;
					}
					else vis[k]=1;
				}
				if (f) break;
				ans++;
				break;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if (a[i]==k){
			vis[i]=1;
			ans++;
		}
	}
	for (int i=1;i<=n;i++){
		if (vis[i]){
			fun(l,i-1);
			l=i+1;
		}
	}
	fun(l,n);
	cout<<ans;
	return 0;
}
