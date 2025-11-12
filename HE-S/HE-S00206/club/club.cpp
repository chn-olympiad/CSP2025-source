#include<bits/stdc++.h>
using namespace std;
int n,t;
int maxx;
bool b[100005];
bool b_1,b_2,b_3;
int maxh;
int a[100005][5];
int c[5];
void dfs(int ans,int sum){
		if(ans==n+1){
			maxx=max(maxx,sum);
			return ;
		}
		int i=ans;
			for(int j=1;j<=3;j++){
				if(!b[i]&& c[j]<maxh){
					b[i]=1;
					c[j]++;
					dfs(ans+1,sum+a[ans][j]);
					b[i]=0;
					c[j]--;
				}
			}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxh=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				c[j]=0;
			}
			b[i]=0;
		} 
		dfs(1,0);
		cout<<maxx<<"\n";
		maxx=0;
		
	}
	return 0;
}
