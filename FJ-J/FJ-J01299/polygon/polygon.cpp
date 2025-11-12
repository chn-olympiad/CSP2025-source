#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,ps1=1;
int l[5050],vsi[5050],vsk[5050]
,vss[5050],vsm[5050],vs[5050],vs_[5050];
void dfs(int i,int k,int s,int mx,int zd){
	if(i>n)return;
	if(k==zd){
		bool fl1=1,fl2=1;
		for(int j=1;j<=zd;j++){
			if(vs[j]!=vs_[j]){
				break;
			}
			if(j==zd)fl1=0; 
		}
		for(int j=1;j<=ans;j++){
			if(!(vsi[j]!=i||vsk[j]!=k||vss[j]!=s||vsm[j]!=mx)){
				fl2=0;break;
			}
		}
		if(mx*2<s&&(fl1||fl2)){
			ans++;
			vsi[ans]=i,vsk[ans]=k,vss[ans]=s,vsm[ans]=mx;
			memset(vs_,0,sizeof vs_);
			for(int j=1;j<=zd;j++){
				vs_[j]=vs[j];
			}
		}
		return;
	}
	for(int j=i+1;j<=n;j++){
		vs[k+1]=j;
		dfs(j,k+1,s+l[j],max(mx,l[j]),zd);
		vs[k+1]=0;
		dfs(j,k,s,mx,zd);
	}
}int A(int n,int m){
	int s=1;
	for(int i=1,j=n;i<=m;i++,j--){
		s*=j;
	}
	return s;
}
int C(int n,int m){
	return A(n,m)/A(m,m);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]!=1)ps1=0;
	}if(ps1==1){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,0,0,0,i);
	}
	cout<<ans;
	return 0;
	//don't forget to delete the // before freopen!!! 
} 
