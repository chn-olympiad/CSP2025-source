#include<bits/stdc++.h>
#define re register
using namespace std;
int n,k;
vector<pair<int,int>> p;
int d(int x){//从x到n可以选择的最大数量 
    int ans=0x3f3f3f3f; 
    bool b=false;
	for(re auto j:p){
		int s=j.first,t=j.second;
		if(s<x) continue;
		else{
			ans=min(ans,t);
			b=true;
		}
	}	
	if(!b) return 0;
	return d(ans+1)+1;;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<int> a(n+1,0);
	vector<int> q(n+1,0);
	for(re int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
		//cout<<q[i]<<" ";
	}
	for(re int i=1;i<=n;i++){
		for(re int j=i;j<=n;j++){
			if((q[i-1]^q[j])==k) {
			    p.push_back({i,j});
			   // cout<<i<<" "<<j<<" "<<(q[i-1]^q[j])<<"\n";
			}
		}
	}
	cout<<d(0)<<"\n";
	return 0;
}
