#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10,mod=998244353,B=233;
int n,q,pw[M];
string s1[N],s2[N],t1[N],t2[N];
vector<int>hss1[N],hss2[N],hst1[N],hst2[N];
int ys1[N],ys2[N],yt1[N],yt2[N],ans[N],Ls[N],Lt[N];
inline int querys1(int i,int l,int r){
	return (hss1[i][r]-(l==0?0:1ll*hss1[i][l-1]*pw[r-l+1]%mod)+mod)%mod;
}inline int querys2(int i,int l,int r){
	return (hss2[i][r]-(l==0?0:1ll*hss2[i][l-1]*pw[r-l+1]%mod)+mod)%mod;
}inline int queryt1(int i,int l,int r){
	return (hst1[i][r]-(l==0?0:1ll*hst1[i][l-1]*pw[r-l+1]%mod)+mod)%mod;
}inline queryt2(int i,int l,int r){
	return (hst2[i][r]-(l==0?0:1ll*hst2[i][l-1]*pw[r-l+1]%mod)+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000000;i++)pw[i]=1ll*pw[i-1]*B%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)cin>>t1[i]>>t2[i];
	for(int i=1;i<=n;i++){
		int len=s1[i].size();
		hss1[i].push_back(s1[i][0]-'a');
		for(int j=1;j<len;j++){
			hss1[i].push_back((1ll*hss1[i][j-1]*B%mod+s1[i][j]-'a')%mod);	
		}
	}
	for(int i=1;i<=n;i++){
		int len=s2[i].size();
		hss2[i].push_back(s2[i][0]-'a');
		for(int j=1;j<len;j++){
			hss2[i].push_back((1ll*hss2[i][j-1]*B%mod+s2[i][j]-'a')%mod);	
		}
	}
	for(int i=1;i<=q;i++){
		int len=t1[i].size();
		hst1[i].push_back(t1[i][0]-'a');
		for(int j=1;j<len;j++){
			hst1[i].push_back((1ll*hst1[i][j-1]*B%mod+t1[i][j]-'a')%mod);	
		}
	}
	for(int i=1;i<=q;i++){
		int len=t2[i].size();
		hst2[i].push_back(t2[i][0]-'a');
		for(int j=1;j<len;j++){
			hst2[i].push_back((1ll*hst2[i][j-1]*B%mod+t2[i][j]-'a')%mod);	
		}
	}
	for(int i=1;i<=n;i++){
		int l=-1,r=-1;
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			if(s1[i][j]!=s2[i][j]){
				l=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[i][j]!=s2[i][j]){
				r=j;
				break;
			}
		}
		Ls[i]=l;
		if(l!=-1)ys1[i]=querys1(i,l,r),ys2[i]=querys2(i,l,r);
	}
	for(int i=1;i<=q;i++){
		if(t1[i].size()!=t2[i].size())continue;
		int l=-1,r=-1;
		int len=t1[i].size();
		for(int j=0;j<len;j++){
			if(t1[i][j]!=t2[i][j]){
				l=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(t1[i][j]!=t2[i][j]){
				r=j;
				break;
			}
		}
		Lt[i]=l;
		if(l!=-1)yt1[i]=queryt1(i,l,r),yt2[i]=queryt2(i,l,r);
	}
//	cout<<yt1[1]<<" "<<ys1[3]<<"\n";
	for(int i=1;i<=q;i++){
		if(t1[i].size()!=t2[i].size())continue;
		for(int j=1;j<=n;j++){
			if(Ls[j]==-1)continue;
			if(ys1[j]!=yt1[i]||ys2[j]!=yt2[i])continue;
			int len=s1[j].size();
			int l=Lt[i]-Ls[j],r=l+len-1;
			if(l<0||r>(int)(t1[i].size()-1))continue;
			if(querys1(j,0,len-1)==queryt1(i,l,r))ans[i]++;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0; 
}
