#include <bits/stdc++.h>
using namespace std;

int n;
int num[3][10001];

int dfs(int a,int b,int c,int x,int p,int ans){
	if(p==1){
		a++;
		ans+=num[0][x];
	}
	if(p==2){
		b++;
		ans+=num[1][x];
	}
	if(p==3){
		c++;
		ans+=num[2][x];
	}
	if((a>n/2)||(b>n/2)||(c>n/2)){
		return 0;
	}
	if(x==n){
		return ans;
	}else{
		x++;
		int aa=dfs(a,b,c,x,1,ans);
		int bb=dfs(a,b,c,x,2,ans);
		int cc=dfs(a,b,c,x,3,ans);
		return max(max(aa,bb),max(bb,cc));
	}
}

void p(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[0][i]>>num[1][i]>>num[2][i];
	}
	int a=dfs(0,0,0,1,1,0);
	int b=dfs(0,0,0,1,2,0);
	int c=dfs(0,0,0,1,3,0);
	cout<<max(max(a,b),max(b,c))<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		p();
	}
	return 0;
}
