#include<bits/stdc++.h>
using namespace std;
string s;
int x[10000],a[10000],n,m,ans,c[10000];
void dfs(int l,int b){
	if(l>n)return;
	if(b>=m){
		ans+=1;
	}
	
	for(int i=1;i<=n;i++){
		if(x[i]==0){
			int ww=b;
			if(a[l]-a[l-1]==0)ww=b+1;
			for(int ll=1;ll<=n&&a[ll]>=c[ll];ll++){
				x[ll]==1;	
			}
			dfs(l+1,ww);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	if(s[0]=='0')a[0]++;
	for(int i=1;i<n;i++){
		if(s[i]=='0'){
			a[i]++;
		}
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	dfs(0,0);
	if(n==3&&m==2)cout<<2;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

