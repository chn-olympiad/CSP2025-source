#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100002];
int b[100002];
int c[100002];
int r[5];
int ans;
int m1=20000,m2=20000,m3=20000;
int an[100002];
int mxan;
void dfs(int s,int as,int bs,int cs,int x){
	if(x>n){
		mxan=max(mxan,s);
		return;
	}
	if(as+1<=n/2){
		dfs(s+a[x],as+1,bs,cs,x+1);	
	}
	if(bs+1<=n/2){
		dfs(s+b[x],as,bs+1,cs,x+1);
	}
	if(cs+1<=n/2){
		dfs(s+c[x],as,bs,cs+1,x+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>T;
	for(int i=1;i<=T;i++){
		cin >>n;
		mxan=0;
		for(int j=1;j<=n;j++){
			cin >>a[j]>>b[j]>>c[j];
		}
		dfs(0,0,0,0,1);
		cout <<mxan<<endl;
 	}
 	return 0;
}
