#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,k,a[N];
int ans;
int count0, count1;
map<pair<long long,pair<int,pair<int,bool> > >,bool> vis;

void dfs(long long xorr,int i,int g,bool in_range){
//	cout<<i<<" "<<xorr<<" "<<g<<" "<<in_range<<"\n";
	if(vis[{xorr,{i,{g,in_range}}}]) return ;
	vis[{xorr,{i,{g,in_range}}}] = 1;
	if(i>=n){
		if(xorr == k) ans = max(ans,g);
		return ;
	}
	
	if(xorr == k && in_range){
		dfs(a[i+1],i+1,g+1,1);
		dfs(0,i+1,g,0);
	}
	if(in_range) dfs(xorr^a[i+1],i+1,g,in_range);
	if(!in_range){
		dfs(xorr,i+1,g,in_range);
		dfs(a[i+1],i+1,g+1,1);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] == 0) count0++;
		if(a[i] == 1) count1++; 
	}
	
	if(count0+count1 == n){
		if(count1 == n){
			cout<<n/2;
		}
		else{
			if(k==1) cout<<count1;
			else if(k == 0) cout<<count0+count1/2; 
		}
		return 0;
	}
	
	dfs(a[1],1,1,1);
	dfs(0,1,0,0);
	
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
