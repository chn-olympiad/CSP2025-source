#include<bits/stdc++.h>
using namespace std;
long long a[500053];
int n,m;
long long ans=0;
map<long long,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)a[i]=a[i]^a[i-1];
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<"\n";
    int ans=0,p=0;
	for(int i=1;i<=n;i++){
		if(mp[a[i]^m]!=0&&mp[a[i]^m]>=p){
			p=i;
			//mp[a[i]^m]=0;
			ans+=1;
//			cout<<a[i]<<"\n";
		}else if(a[i]==m){
			if(ans==0)ans+=1; 
			p=i; 
		}
		mp[a[i]]=i;
	}
	cout<<ans;
	return 0;
} 
