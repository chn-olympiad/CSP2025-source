#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1000];
int ans=0;
void dfs(vector<int> v,vector<int> f){
	if(v.size() == n){
		int len=0;
		for(int i=0;i<s.size();i++){
			if(s[i] == '0'){
				len+=1;
			}
			else{
				if(v[i]<=len){
					len+=1;
				}
				else{
					continue;
				}
			}
		}
		if(v.size()-len>=m){
			ans+=1;
		}
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!f[i]){
				vector<int> a1(f);
				vector<int> a2(v);
				a2.push_back(a[i]);
				a1[i]=1;
				dfs(a2,a1);
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> f(30,0);
	vector<int> v;
	dfs(v,f);
	cout<<ans;
}

