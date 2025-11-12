#include<bits/stdc++.h>
using namespace std;
int t,n,sum = 0;
void dfs(int a,int b,int c){
	while(t--){
	for(int i = 1;i<=n;++i){
		int a,b,c;
		cin>>a>>b>>c;
		int x = max(a,b);
		int y = max(x,c);
		if(y==a){
			a++;
		}
		if(y==b){
			b++;
		}
		if(y==c){
			c++;
		}if(c==n/2||b==n/2||a==y/2){
			dfs(0,0,0);
			continue;
		}
		sum+=y;
	}cout<<sum;
}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t>>n;
	dfs(0,0,0);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
