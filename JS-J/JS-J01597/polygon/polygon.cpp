#include<bits/stdc++.h>
using namespace std;
long long n,a[6000],b[6000],vis[6000],ans,anss;
void dfs(int x,int y,int l){
	if(x==y+1){
		int p=0;
		for(int i=1;i<y;i++){
			p+=b[i];
		}
		if(p>b[y]){
			/*for(int i=1;i<=y;i++){
				cout<<b[i]<<' ';
			}	
			cout<<endl;*/
			anss+=1;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&i>l){
				vis[i]=1;
				b[x]=a[i];
				dfs(x+1,y,i);
				vis[i]=0;
			}
		
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		anss=0;
		for(int j=1;j<=n;j++) b[j]=0;
		dfs(1,i,0);
		ans+=anss;
		ans%=998244353;
	}

	cout<<ans%998244353;
	return 0;
}
