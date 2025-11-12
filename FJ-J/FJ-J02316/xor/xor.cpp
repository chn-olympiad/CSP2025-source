#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=a[i];
		for(int j=i+1;j<=n;j++){
			t^=a[j];
			if(t==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<max(ans,cnt);
	return 0;
}
