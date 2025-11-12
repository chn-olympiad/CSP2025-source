#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,b;
int a[500010];
int cnt;
int xr[500010];
int cnt1;
bool vis[500010];
vector<pair<int,int> >v;
bool f1,f2,f3;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		if(a[i]!=1)f1=1;
		if(a[i]>1)f2=1;
	}
	if(!f1)cout<<n/2;
	else if(!f2){
		if(k==1){
			cout<<cnt1;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				if(a[i]==1&&a[i+1]==1)cnt++,i++;
			}cout<<cnt;
		}
	}
	else{
		for(int i=1;i<=n;i++)xr[i]=xr[i-1]^a[i];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n-i;j++){
//				cout<<j+1<<' '<<j+i<<' '<<(xr[j+i]^xr[j])<<'\n';
				if((xr[j+i]^xr[j])==k)v.push_back({j+1,j+i});
			}
		}
		for(auto p:v){
			bool f=0;
			for(int i=p.first;i<=p.second;i++){
				if(vis[i]){
					f=1;
					break;
				}
			}if(!f){
	//			cout<<p.first<<' '<<p.second<<endl;
				for(int i=p.first;i<=p.second;i++){
					vis[i]=1;
				}
				cnt++;
			}
		}cout<<cnt;
	}
	return 0;
}
