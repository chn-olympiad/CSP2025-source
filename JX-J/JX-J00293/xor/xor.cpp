#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],ans,t;
vector<int> idx[1500];

void dfs(int h){
	int u=0;
	if(h!=0)u=b[h-1]^k;
	int l=idx[u].size();
	if(a[h]==k){
		t++;
		ans=max(ans,t);
		dfs(h+1);
		t--;
	}
	if(h!=0){
		for(int i=0;i<l;i++){
			if(idx[u][i]>=h){
				//cout<<h<<' '<<idx[u][i]<<endl;
				t++;
				ans=max(ans,t);
				dfs(idx[u][i]+1);
				t--;
			}
		}
	}else{
		for(int i=1;i<n;i++){
			if(b[i]==k){
				t++;
				ans=max(ans,t);
				dfs(i+1);
				t--;
			}
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0)b[i]=b[i-1]^a[i];
		else b[i]=a[i];
		idx[b[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		dfs(i);
		ans=max(t,ans);
		t=0;
	}
	cout<<ans;
	
	return 0;
}
