#include<iostream>
#include<algorithm>
using namespace std;
int t;
int n;
long long ax[10][100005];
long long ans=0,id=0x3f3f3f3f;
void DFS(int x,long long sum,int a,int b,int c){
	if(x>=n+1&&a<=n/2&&b<=n/2&&c<=n/2){	
		if(sum>=ans){
			ans=sum;
			id=x;
		}
		return ;
	}
	if(a>n/2||b>n/2||c>n/2||(ans>=sum&&id<x)){
		return ;
	}
	if(sum>=ans){
		ans=sum;
		id=x;
	}
	if(a+1<=n/2&&ax[1][x]!=0){
		DFS(x+1,sum+ax[1][x],a+1,b,c);
	}
	if(b+1<=n/2&&ax[2][x]!=0){
		DFS(x+1,sum+ax[2][x],a,b+1,c);
	}
	if(b+1<=n/2&&ax[3][x]!=0){
		DFS(x+1,sum+ax[3][x],a,b,c+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ax[1][i]>>ax[2][i]>>ax[3][i];
		}
		DFS(1,0,0,0,0);
		cout<<ans<<'\n';
		ans=0;
		id=0x3f3f3f3f;
	}
	return 0;
}


