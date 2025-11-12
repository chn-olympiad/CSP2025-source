#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],tt,sum=1;
bool cmp(int p,int q){
	return p>=q;
}
void dfs(int x,int y,int j){
	if(a[j]==tt){
		cout<<y<<" "<<x;
		return;
	}
	if(n==1){
		dfs(x,y+1,j+1);
	}
	else{
		if(x==n){
			if(a[j+1]==tt){
				cout<<y+1<<" "<<x;
				return;
			}
			else{
				sum=-1;
				dfs(x-1,y+1,j+2);
			}
		}
		else if(x==1){
			if(a[j+1]==tt){
				cout<<y+1<<" "<<x;
				return;
			}
			else{
				sum=1;
				dfs(x+1,y+1,j+2);
			}
		}
		else{
			dfs(x+sum,y,j+1);
		}
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tt=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(tt==a[1]){
		cout<<1<<" "<<1;
		return 0;
	}
	dfs(2,1,2);
	return 0;
}