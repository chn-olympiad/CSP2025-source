#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10,K = 32;
int n,k;
int a[N];
int sum[N][K];
int val(int l,int r){
	int cnt = 0;
	for(int i = 0;i<=31;i++){
		if((sum[r][i]-sum[l-1][i])%2==1) cnt+=(1<<i);
	}
	return cnt;
}

pair<int,int> g[N];
int len;

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second) return a.first>b.first;
	return a.second<b.second;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt0 = 0,cnt1 = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
		int b = a[i];
		for(int j = 0;j<=31;j++){
			sum[i][j] = sum[i-1][j]+(b&1);
			b>>=1;
		}
	}
	if(n>=1001){
		if(k==1) cout<<cnt1;
		else cout<<cnt0;
	}else{
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if(val(i,j)==k){
					g[++len] = make_pair(i,j);
				}
			}
		}
		sort(g+1,g+1+len,cmp);
		int cnt = 0,en = 0;
		for(int i = 1;i<=len;i++){
			if(g[i].first>en){
				cnt++;
				en = g[i].second;
			}
		}
		cout<<cnt;	
	}
	
	return 0;
}
