#include<bits/stdc++.h>
using namespace std;	
int b[1000];
int t,n,a[100005][3],d;
int ans,cnt;
void dfs(int dep,int n){
	if(b[1]>d||b[2]>d||b[3]>d) return;
	if(dep>n){
		ans=max(ans,cnt);
		return;
	}
		for(int j=1;j<=3;j++){
			b[j]+=1;
			cnt+=a[dep][j];
			dfs(dep+1,n);
			b[j]-=1;
			cnt-=a[dep][j];
		}
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		d=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}	
		dfs(1,n);
		cout<<ans;
		ans=0;cnt=0;
	}
	
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

