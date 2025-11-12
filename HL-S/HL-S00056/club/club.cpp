#include<bits/stdc++.h> 
using namespace std;
int T,n;
int maxx=0;
int f[4];

int e[100050][4];
int DF(int x,int w){
	int k=n>>1;
	if(x>n){
		return maxx=max(maxx,w);
	}
	for(int i=1;i<=3;i++){
		if(f[i]<k){
			f[i]++;
			DF(x+1,w+e[x][i]);
			f[i]--;
		}
		
	}
	return maxx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int II=1;II<=T;II++){
		memset(f,0,sizeof(f));
		memset(e,0,sizeof(e));
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i][1]>>e[i][2]>>e[i][3];
		}
		cout<<DF(1,0)<<endl;
		
	}
	return 0;
}
