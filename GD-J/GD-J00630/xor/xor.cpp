#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+2;
int n,k,cnt;
int a[N];
int s[N];
vector<pair<int,int>> v;
bool flag=true;
void dfs(int dep,int tot,int r){
	if(dep>v.size()-1){
		cnt=max(cnt,tot);
		return ;
	}
	dfs(dep+1,tot,r);
	if(r<v[dep].first)dfs(dep+1,tot+1,v[dep].second);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]>1)flag=0;
	}
	if(flag){
		int tmp=0,cnt1=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i])cnt1++;
				else tmp++;
				if(cnt1==2)tmp++,cnt1=0;
			}	
		}else{
			for(int i=1;i<=n;i++){
				if(a[i])tmp++;
			}
		}
		cout<<tmp;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				v.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0,0,0);
	cout<<cnt;
}
