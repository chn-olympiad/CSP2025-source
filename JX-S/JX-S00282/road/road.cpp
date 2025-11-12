#include<bits/stdc++.h>
using namespace std;
int f[1000100],t[1000100],s[1000100],re[10001]={0},mx=1,n,m,k,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		cin>>f[i]>>t[i]>>s[i];
		if(s[i]>mx) mx=s[i];
    }
	for(int i=1;i<=m;i++){
		if(s[i]<mx) ans+=s[i];
		else mx--;
		re[f[i]]++; 
		re[t[i]]++;
    } 
	for(int i=1;i<=n;i++) if(re[i]==0) return 0;
	cout<<ans;
}
