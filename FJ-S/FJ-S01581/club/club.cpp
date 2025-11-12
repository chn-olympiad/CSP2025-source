#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][4];
int maxx;
priority_queue<int> q;
void dfs(int c,int num1,int num2,int num3,int ans){
	maxx=max(maxx,ans);
	if(num1+1<=n/2){
		dfs(c+1,num1+1,num2,num3,ans+a[c][1]);
	}
	if(num2+1<=n/2){
		dfs(c+1,num1,num2+1,num3,ans+a[c][2]);
	}
	if(num3+1<=n/2){
		dfs(c+1,num1,num2,num3+1,ans+a[c][3]);
	}
}
void dfs1(int c,int num1,int num2,int ans){
	maxx=max(maxx,ans);
	if(a[c][1]>a[c][2]){
		if(num1+1<=n/2){
			dfs1(c+1,num1+1,num2,ans+a[c][1]);
		}else if(num2+1<=n/2){
			dfs1(c+1,num1,num2+1,ans+a[c][2]);
		}
	}else{
		if(num2+1<=n/2){
			dfs1(c+1,num1,num2+1,ans+a[c][2]);
		}else if(num1+1<=n/2){
			dfs1(c+1,num1+1,num2,ans+a[c][1]);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		maxx=0;
		if(n<=10){
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			dfs(0,0,0,0,0);
			cout<<maxx<<"\n";
		}else{
			maxx=0;
			bool f=1;
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				if(a[i][2]!=0||a[i][3]!=0){
					f=0;
				}
			}
			if(f){//A
				for(int i=1;i<=n;i++){
					q.push(a[i][1]);
				}
				for(int i=1;i<=n/2;i++){
					maxx+=q.top();
					q.pop();
				}
				cout<<maxx<<"\n";
				while(!q.empty()){
					q.pop();
				}
			}else{//B
				dfs1(0,0,0,0);
				cout<<maxx<<"\n";
			}
		}
	}
	return 0;
} 
