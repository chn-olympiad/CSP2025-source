#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5;
int n=0,a[N][4],t,cnt,f[N];
int dfs(int num,int x,int y,int z){
	if(num<1) return 0;
	else{
		f[num]=dfs(num-1,x,y,z);
		f[num]=max((x<n/2)*(dfs(num-1,x+1,y,z)+a[num][1]),f[num]);
		f[num]=max((y<n/2)*(dfs(num-1,x,y+1,z)+a[num][2]),f[num]);
		f[num]=max((z<n/2)*(dfs(num-1,x,y,z+1)+a[num][3]),f[num]);
	}
	return f[num];
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		for(int i=0;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=-1;
			}
	    }
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(n,0,0,0)<<endl;
	}
	
	return 0;
}
