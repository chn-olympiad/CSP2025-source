#include<bits/stdc++.h>
using namespace std;

int n,a[6000],m;
bool b[6000];

void bfs(int x,int bm,int ans,int last){
	if(x<=0){
		if(ans>2*bm){
			m=(m+1)%998244353;
		}
		return ;
	}
	for(int i=last+1;i<=n;i++){
		if(b[i]==1){
			continue;
		}
		b[i]=1;
		bfs(x-1,max(bm,a[i]),ans+a[i],i);
		b[i]=0;
		
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		memset(b,0,sizeof(b));
		bfs(i,0,0,0);
	}
	cout<<m;
	
	return 0;
}
