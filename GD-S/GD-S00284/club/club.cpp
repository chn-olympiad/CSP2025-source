#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int t,n;
int mxin,ans;
int a[N][5];
void dfs(int v1,int v2,int v3,int s,int ansf){
	if(v1<mxin&&v1+v2+v3<n){
		ansf+=a[s][1];
		if(ans<ansf) ans=ansf;
		if(ansf+a[s+1][4]>ans|| s<n){
			dfs(v1+1,v2,v3,s+1,ansf);
		}
		ansf-=a[s][1];
	}
	if(v2<mxin&&v1+v2+v3<n){
		ansf+=a[s][2];
		if(ans<ansf) ans=ansf;
		if(ansf+a[s+1][4]>ans|| s<n){
			dfs(v1,v2+1,v3,s+1,ansf);
		}
		ansf-=a[s][2];
	} 
	if(v3<mxin&&v1+v2+v3<n){
		ansf+=a[s][3];
		if(ans<ansf) ans=ansf;
		if(ansf+a[s+1][4]>ans || s<n){
			dfs(v1,v2,v3+1,s+1,ansf);
		}
		ansf-=a[s][3];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		mxin=n/2;
		ans=0;
		int v1=0,v2=0,v3=0;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][4]=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		dfs(0,0,0,1,0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
