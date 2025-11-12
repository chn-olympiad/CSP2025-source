#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N][10],mx,js[5];
void dfs(int st,int cnt){
	if(st>n){
		mx=max(mx,cnt);
		
		return ;
	}
	
		for(int j=1;j<=3;j++){
			if(js[j]+1<=(n/2)){
				cnt+=a[st][j];
				
				js[j]++;
				dfs(st+1,cnt);
				js[j]--;
				cnt-=a[st][j];
			}
		}
	
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			js[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		mx=0;
		dfs(1,0);
		cout<<mx<<endl;
	}
	return 0;
}
