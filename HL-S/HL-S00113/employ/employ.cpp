#include<bits/stdc++.h>
using namespace std;
int n,m,c[100001],ans;
bool t[100001],vis[10001],gone[10001];
string s;
void dfs(int l,int ct,int k){
	if(l>=n){
//		cout<<'\t'<<k<<'\t';
		if(k>=m){ans++;
//		cout<<"T"<<endl;
		}
//		else cout<<"N"<<endl;
		return;
	}
//	cout<<l<<' '<<k<<' '<<c[l]<<":"<<ct<<' ';
//	if(c[l]<ct){
////	cout<<c[l]<<":"<<ct<<"gone"<<endl;
//	gone[l]=1;return;};
	queue<int>temp;
	for(int i=1;i<=n;i++){
		if(c[i]<=ct&&!gone[i]&&!vis[i]){
//			cout<<l<<' '<<i<<"gone\n";
			gone[i]=1;
			temp.push(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!gone[i]){
			vis[i]=1;
//			cout<<i<<endl;
			if(t[i])dfs(l+1,ct,k+1);
			else	dfs(l+1,ct+1,k);
			vis[i]=0;
		}
	}
	while(!temp.empty()){
		int t=temp.front();temp.pop();
		gone[t]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
//	cout<<s<<endl;
	bool flag=0;
	for(int i=0;i<=s.size();i++){
		t[i+1]=s[i]-'0';flag=t[i+1];
	}
//	for(int i=1;i<=m+1;i++)cout<<t[i];
//	cout<<endl;
	if(flag){cout<<0<<endl;return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
