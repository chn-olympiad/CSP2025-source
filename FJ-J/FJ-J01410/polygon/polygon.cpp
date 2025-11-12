# include <bits/stdc++.h>
using namespace std;
int n,m;
bool v[6000];

long long int a[6000],qz[6000],ans=0,path[6000];
void dfs(int c,long long maxn,int syg,int cdh,int hh){
	if(c>hh){
		if(maxn*2<cdh){
			ans++;
		} 
		
		return;
	}else{
		for(int i=syg+1;i<=n;i++){
			
			if(v[i]==0){
				v[i]=1;
				path[c]=a[i];
				dfs(c+1,max(maxn,a[i]),i,cdh+a[i],hh);
				path[c]=0;
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	bool sf=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) sf=1;
		qz[i]=qz[i-1]+a[i];
	} 
	if(sf==0){
		cout<<n-2;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,0,0,i);
	}
	cout<<ans<<"\n";
	return 0;
}
