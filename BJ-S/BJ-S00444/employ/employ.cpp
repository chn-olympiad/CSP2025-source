#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
const int p=998244353;
int n,m;
string s;
int c[110];
int cnt2[110];
bool vis[110];
int box[110];
int ans=0;

ll jc(int x){
	ll aaa=1;
	for(int i=x;i>=1;i--){
		aaa=(aaa*x)%p;
	}
	return aaa%p;
}


void dfs(int cur){
	
	if(cur>n){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			
			if(s[i]=='0') {
				cnt++;
				//continue;
			}
			else if(c[box[i]]>cnt){
				sum++;
			}else{
				cnt++;
			}
			//cout<<i<<" "<<s[i]<<" "<<cnt<<" "<<sum<<"\n";
			//cout<<c[box[i]]<<" ";
		}
		//cout<<"\n";
		//cout<<cnt<<"\n";
		if(sum>=m){
			ans=(ans+1)%p;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		box[cur]=i;
		vis[i]=1;
		dfs(cur+1);
		vis[i]=0;
	}
	
	
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='$'+s;
	int ss=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) ss++;
	}
	if(n<=18) dfs(1);
	
	
	
	else{
		if(ss<m){
			cout<<0;
			return 0;
		}else{
			cout<<jc(n);
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
