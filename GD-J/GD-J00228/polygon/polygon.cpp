#include<bits/stdc++.h>
using namespace std;
int n,op,a[5099],opp,x1,b[5099];
void dfs(int x,int y){
	if(x > x1){
		int g=0,s=0;;
		for(int i=1;i<x;i++){
//			cout<<b[i]<<" ";
			g+=b[i];
			s=max(s,b[i]);
			
		}
//		cout<<g<<" "<<s<<" ";
		s=s*2;
		if(g>s){
			
			opp+=1;
//			cout<<op<<" ";
		}
//		cout<<endl;
		return;
	}
	for(int i=y+1;i<=(n-x1+x);i++){
		b[x]=a[i];
		dfs(x+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int m=3;m<=n;m++){
		opp=0;
		x1=m;
		dfs(1,0);
		op+=opp;
	}
	int g=op % 998244353;
	cout<<op;
}
