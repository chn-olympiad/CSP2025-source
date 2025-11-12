#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,m;
int a[500005];
long long dis[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i]=a[i]^dis[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			m=dis[r]^dis[l-1];
			if(m==k){
				cnt++;
				l=r;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
