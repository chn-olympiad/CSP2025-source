#include <bits/stdc++.h>
using namespace std; 
int n,k,ans,maxa,cnt,a[500005][25];
int s[500005][25];
vector<int> h[500005];

void dfs(int x){
	for(int i=x+1;i<=n;i++){
		for(auto it:h[i]){
			ans++;
			maxa=max(maxa,ans);
			dfs(it);
			ans--;
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		cnt+=(a[i][0]==1);
		int d=a[i][0],top=0;
		while(d!=0){
			a[i][++top]=d%2;
			d/=2;
		}
	}
	if(cnt==n){
		cout << n/2;
		return 0;
	}
	cnt=0;
	while(k!=0){
		s[0][++cnt]=k%2;
		k/=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int l=1;l<=20;l++){
				if((s[j][l]-s[i-1][l])%2!=s[0][l]) flag=0;
				if(!flag) break;
			}
			if(flag) h[i].push_back(j);
		}
	}
	dfs(0);
	cout << maxa;
	return 0;
}
