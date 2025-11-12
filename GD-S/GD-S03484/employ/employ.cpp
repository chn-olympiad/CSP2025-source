#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],ord[1000],ans;
char s[1000];
bool v[1000];
void dfs(int cnt){
	if(cnt==n+1){
		int cntout=0;
		for(int i=1;i<=n;i++){
//			cout<<ord[i]<<" ";
			if(s[i]=='0'){
				cntout++;
			}
			else if(cntout>=c[ord[i]]){
				cntout++;
			}
		}
//		cout<<cntout<<endl;
		if((n-cntout)>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			ord[cnt]=i;
			dfs(cnt+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
