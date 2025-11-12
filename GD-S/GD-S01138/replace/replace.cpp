#include<bits/stdc++.h> 
using namespace std;
int n,q;
long long ans;
string a[200005][2];
string s1,s2;
bool b[200005];

void dfs(string s,string s1,string s2,int t){
	if(t>=s1.size()){
		if(s==s2){
			ans++;
		}
		return;
	}
	dfs(s+s1[t],s1,s2,t+1);
	for(int i=0;i<n;i++){
		bool fl=0;
		if(b[i]==1)continue;
		for(int j=0;j<a[i][0].size();j++){
			if(t+j>=s1.size()||a[i][0][j]!=s1[t+j]){
				fl=1;
				break;
			}
		}
		if(fl==0){
			b[i]=1;
			dfs(s+a[i][1],s1,s2,t+a[i][1].size());
			b[i]=0;
		}
	}
	return;
}


void solve(){
	ans=0;
	cin>>s1>>s2;
	dfs("",s1,s2,0);
}


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<q;i++){
		solve();
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
