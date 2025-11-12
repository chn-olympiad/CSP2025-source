#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int cnt=0;
bool v[505];
void dfs(int x,int t){
	if(x>n){
		if(t>=m){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(s[x]=='0'||x-1-t>=c[i]){
				dfs(x+1,t);
			}
			else{
				dfs(x+1,t+1);
			}
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int count=0;
	for(char i:s){
		if(i=='1'){
			count++;
		}
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(count==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(long long)(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(count<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
	/*
	while(1){
		cout<<"RP++\n";
	}
	*/ 
}

