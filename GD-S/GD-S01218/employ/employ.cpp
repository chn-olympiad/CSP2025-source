#include<bits/stdc++.h>
using namespace std;
const int N=560,mod=998244353;
string c;
int n,m,a[N],sum[N],mx=0;
long long ans=0;
bool cmp(int x,int y){
	return c[x]<c[y];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	cin >> c;
	for(int i=0;i<n;i++){
		if(c[i]==1){
			sum[i]=sum[i-1]+1;
		} 
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	if(sum[n-1]<m){
		cout << 0;
		return 0;
	}
	if(n==m){
		bool flag=true;
		long long ss=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				flag=false;
				break;
			}
			ss*=i;
			ss%=mod;
		}
		if(flag){
			cout << ss ;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	if(m==n){
		long long ss=1,as=0;
		for(int i=1;i<=n;i++){
			if(sum[i-1]>mx){
				break;
			}
			ss*=i;
			ss%=mod;
			ans+=ss;
		}
		cout << ans;
		return 0;
	}
	if(sum[n-1]==n){
		int s=1,cs=0;
		vector<int> tt;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cs++;
			}
			else{
				tt.push_back(i);
			}
		}
		if(n-cs<m){
			cout << 0;
			return 0;
		}
	}
	return 0;
}
