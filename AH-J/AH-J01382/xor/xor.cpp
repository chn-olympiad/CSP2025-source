#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k;
int a[500005];
int b[500005];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int i=1;
	int minn=n;
	while(i<=n){
		for(;i<=min(minn,n);i++){
			for(int j=i;j<=min(minn,n);j++){
				if((b[j]^b[i-1])==k){
					minn=min(minn,j);
					break;
				}
			}
		}
		if(minn==n+10){
			break;
		}
		i=minn+1;
		minn=n+10;
		ans++;
	}
	cout<<ans;
}
