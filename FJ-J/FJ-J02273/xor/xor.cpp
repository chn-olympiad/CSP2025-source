#include<bits/stdc++.h>
using namespace std;
int n,k,a[5*100086],c[5*100086],t=0,ans=0;
vector<pair<int,int> >v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if((c[i-1]^c[j])==k)v.push_back(make_pair(j,i));
	sort(v.begin(),v.end());
	for(auto p:v)if(p.second>t)t=p.first,ans++;
	cout<<ans<<endl;
}

