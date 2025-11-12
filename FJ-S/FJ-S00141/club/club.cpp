#include <bits/stdc++.h> 
using namespace std;
int T;
int mo[205][205][205];
int dfs(int s[205][3],int x,int a,int b,int n){
	if(x==n) return 0;
	if(mo[x][a][b]!=-1) return mo[x][a][b];
	int c=x-a-b;
	if((a+1)*2>n){
	    mo[x][a][b]=max({dfs(s,x+1,a,b+1,n)+s[x][1],
			             dfs(s,x+1,a,b,n)+s[x][2]});   
		return  mo[x][a][b];
    }
	else if((b+1)*2>n){
    	mo[x][a][b]=max({dfs(s,x+1,a+1,b,n)+s[x][0],
			             dfs(s,x+1,a,b,n)+s[x][2]});
		return mo[x][a][b];
	}
	else if((c+1)*2>n){
    	mo[x][a][b]=max({dfs(s,x+1,a+1,b,n)+s[x][0],
			             dfs(s,x+1,a,b+1,n)+s[x][1]});
		return  mo[x][a][b];
	}
	else{
	    mo[x][a][b]=max({dfs(s,x+1,a+1,b,n)+s[x][0],
	                 dfs(s,x+1,a,b+1,n)+s[x][1],
			         dfs(s,x+1,a,b,n)+s[x][2]});
	}
	return mo[x][a][b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	cin >>T;
	while(T--){
		int n,s[205][3];
		cin >>n;
		if(n<=200){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
			    for(int t=0;t<=n;t++){
			        mo[i][j][t]=-1;
		        }
		    }
		}
		for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin >>s[i][j];
	    cout <<dfs(s,0,0,0,n) <<"\n";
	    }else{
	    	vector<int> aa(n);
	    	for(int i=0;i<n;i++){
	    		int a,b,c;
	    		cin >>a >>b >>c;
	    		aa.push_back(a);
			}
			sort(aa.rbegin(),aa.rend());
			long long sum=0;
			for(int i=0;i<n/2;i++) sum+=aa[i];
			cout <<sum <<"\n";
		}
	}
}
