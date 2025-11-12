#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int b[N][3];
int asd[50][50][50][50];
int ans=0;
int n;
void dfs(int k,int an,int bn,int cn,int cnt){
//	for(int i=1;i<k;i++){
//		cout<<"  ";
//	}
//	cout<<k<<" "<<an<<" "<<bn<<" "<<cn<<" "<<cnt<<"\n";
	if(k>n){
		ans=max(ans,cnt);
		return;
	}
	if(asd[k][an][bn][cn]>cnt){
		return;
	}
	asd[k][an][bn][cn]=cnt;
	if(an<n/2){
		dfs(k+1,an+1,bn,cn,cnt+b[k][0]);
	}
	if(bn<n/2){
		dfs(k+1,an,bn+1,cn,cnt+b[k][1]);
	}
	if(cn<n/2){
		dfs(k+1,an,bn,cn+1,cnt+b[k][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset (asd,0,sizeof(asd));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[i][0]>>b[i][1]>>b[i][2];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}