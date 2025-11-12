#include<bits/stdc++.h>
//O(n^2)
//tot_get:30~60
using namespace std;
vector<pair<int,pair<int,int> > >  v;
int a[500010];
int h[1048590]; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flag=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	if(!flag){
		if(k>1){
			cout<<0<<'\n';
			return 0;
		}
		int ans=0;
		for(int i=0;i<n;){
			int tot=0;
			for(int j=i;j<n;j++){
				tot^=a[j];
				if(tot==k){
					i=j;
					ans++;
					break;
				}
			}
			i++;
		}
		cout<<ans<<'\n';
	}
	else{
	for(int i=0;i<n;){
		int tot=0;
		for(int j=i;j<n;j++){
			tot^=a[j];
			if(tot==k){
				v.push_back({j-i+1,{i,j}});
				break;
			}
		}
		i++;
	}
	int ans=0;
	for(int i=0;i<(int)v.size();i++){
		int val=0;
		for(int j=v[i].second.first;j<=v[i].second.second;j++){
			if(h[j]){
				val=1;
				break;
			}
		}
		if(val) continue;
		ans++;
		for(int j=v[i].second.first;j<=v[i].second.second;j++){
			h[j]=1;
		}
	}
	cout<<ans<<'\n';
	}
	return 0;
}
