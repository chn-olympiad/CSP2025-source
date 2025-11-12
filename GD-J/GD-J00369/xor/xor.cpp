#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k;
int g[N];
int minl=2,maxl=0;
int pd(){
	int ans;
	int tt;
	int cnt;
	for(int i=1;i<=n;i++){
		cnt=g[i];
		tt=i;
		while(cnt!=k&&tt<=n){
			tt++;
			cnt=cnt^g[tt];
		}
		if(cnt==k){
			ans++;
			i=tt;
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>g[i];
		minl=min(minl,g[i]);
		maxl=max(maxl,g[i]);
	}
	if(minl==1&&maxl==1){
		cout<<n/2;
		return 0;
	}
	if(minl==0&&maxl==1){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(g[i]==0)cnt++;
				if(g[i]==1&&g[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
			return 0;
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(g[i]==1)cnt++;
				if(g[i]==0&&g[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	cout<<pd();
	return 0;
}

