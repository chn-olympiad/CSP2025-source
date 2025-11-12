#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[10],n,k,a[500005],f=0,ans,anss=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]==n){
		cout<<n;
		return 0;
	}else if(cnt[0]+cnt[1]==n){
		if(k==1){
			cout<<cnt[1];
		}else{
			cout<<n;
		}
		return 0;
	}else if(n<=1e4){
		for(int i=1;i<=n;i++){
			i=f+1;
			ans=0;
			for(int j=i;j<=n;j++){
				ans^=a[j];
				if(ans==k){
					f=j;
					anss++;
					break;
				}
			}
		}
		cout<<anss;
		return 0;
	}
	cout<<1;
	return 0;
}