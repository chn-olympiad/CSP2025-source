#include<bits/stdc++.h>
using namespace std;
int a[101],nx,mx,n,m;
int cmd(int a,int b){
	return a>b;
}
int dfs(int k,int x,int y,int f){
	if(k==1){
		nx=x;
		mx=y;
		return 0;
	}else{
		cout<<x<<" "<<y<<endl;
		if(f==0){
			if(n==x){
				dfs(k-1,x,y+1,2);
			}else{
				dfs(k-1,x+1,y,0);
			}
		}else if(f==2){
			if(x==1){
				dfs(k-1,x,y+1,0);
			}else{
				dfs(k-1,x-1,y,2);
			}
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
	int q=a[1],w;
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=i;
			break;
		}
	}

	dfs(w,1,1,0);
	cout<<mx<<" "<<nx;
	return 0;
}

