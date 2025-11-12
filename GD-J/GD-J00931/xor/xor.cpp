#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+20;
int n,k;
int a[maxn];
int sum[maxn];
int book[maxn][2];
int dp[maxn];
void solve1(){
	cout<<1;
	return;
}
void solve2(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)cnt++;
	}
	if(k==0)cout<<cnt;
	else cout<<n-cnt;
}
bitset<maxn> vis;
void solve(){
	int ma=k;
	for(int i=1;i<=n;i++)ma=max(ma,a[i]);
	int len=log2(ma)+1;
	for(int t=0;t<=len;t++){
		//cerr<<"t="<<t<<"\n";
		int u=(k>>t)&1;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>k)&1){
				cnt1++;
			}else{
				cnt0++;
			}
			book[i][0]=cnt0,book[i][1]=cnt1;
		}
		for(int i=1;i<=n;){
			int j=n;
			while(j>=i){
				if((book[j][u]-book[i-1][u])&1){
					break;
				}
				j--;
			}
			if(j>=i){
				if(t==0){
					for(int temp=i;temp<=j;temp++){
						vis[temp]=1;
					}
				}else{
					for(int temp=1;temp<=n;temp++){
						if(temp>=i&&temp<=j)vis[temp]=vis[temp]&1;
						else vis[temp]=0;
					}
				}
				i=j+1;
				//cerr<<i<<" "<<j<<"\n";
			}else{
				i++;
			}
			
		}
	}
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(ans>0){
				cnt++;
			}
		}else{
			ans++;
		}
	}
	cout<<cnt<<"\n";
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=false;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=true;
			break;
		}
	}
	if(!f){solve1();
	}else{
		f=false;
		for(int i=1;i<=n;i++){
			if(a[i]!=0&&a[i]!=1){
				f=true;
				break;
			}
		}
		if(!f){
			solve2();
		}else{
			solve();
		}
	}
	return 0;
}
