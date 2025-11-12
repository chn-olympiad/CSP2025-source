#include<bits/stdc++.h>
using namespace std;
//有0为1，无0为0;^^^^^
int n,k;
int a[500005];
int vi[500005];
int ans=0;
int y(int x,int y){
	int cnt;
	for(int i=1;;i++)
		bool c=x%2;
		bool b=y%2;
		x/=2;
		y/=2;
		
		if(x==0&&y==0){
			break;
		}
	}
	return cnt;
}
void dfs(int s) {
	for(int i=s; i<=n; i++) {
		if(vi[i]==0){
			
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		if(n==1){
			if(a[1]==k){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			int wqe=0;
			if(a[1]==k){
				wqe++;
			}
			if(a[2]==k){
				wqe++;
			}
			cout<<wqe
		}
	}else{
		cout<<0;
	}
	return 0;
}
