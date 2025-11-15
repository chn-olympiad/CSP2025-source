#include<bits/stdc++.h>
using namespace std;

const int INTM = 20000000;
int a[INTM][4]={};
bool bj[INTM][4];

int ans=0;
int tans[INTM]={};
int t,n,rs[4]={};

void dfs(int member,int bm,int score,int rs[4]){
	int c = score;
	bj[member][bm] = true;
	if(member==n-1){
		c+=a[member][bm];
		if(c>ans) ans=c;
		bj[member][bm]=false;
		return;
	}
	c+=a[member][bm];
	rs[bm]++;
	for(int i=0;i<3;i++){
		if(bj[member+1][i]==false && (rs[i]+1)<=(n/2)){
			dfs(member+1,i,c,rs);
		}
	}
	bj[member][bm]=false;
	rs[bm]--;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	
	cin>>t;
	int tt=t;
	while(t--){
		for(int i=0;i<4;i++) rs[i]=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<3;j++){
				bj[i][j]=false;
			}
		}
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		dfs(0,0,0,rs);
		dfs(0,1,0,rs);
		dfs(0,2,0,rs);
		tans[tt-t-1]=ans;
		
		//reset below
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				a[i][j]={};
			}
		}
		ans=0;
	}
	for(int i=0;i<tt;i++){
		cout<<tans[i]<<endl;
	}
	return 0;
}
