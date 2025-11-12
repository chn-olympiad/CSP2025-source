#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],b[N];
bool v[N];
int now[N],idx;
int ans=0;	
int n,m;
void dfs(int u){
	if(u>n){
		int sum=0;
		for(int i=1; i<=n; i++){
		//	cout<<"b="<<b[now[i]]<<" i="<<i<<endl;
			if(b[i]>=now[i])sum++;
		//	cout<<i<<" "<<now[i]<<endl;	
		}
	//	cout<<endl;
		if(sum>=m){ans++;}
		return;
	}else{
		for(int i=u; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(!v[j]){
					now[j]=i;
					v[j]=1;
					dfs(u+1);
					v[j]=0;
					now[j]=0;
				}
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=0; i<s.size(); i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1; i<=n; i++)cin>>b[i];
	dfs(1);
	cout<<ans;
}
