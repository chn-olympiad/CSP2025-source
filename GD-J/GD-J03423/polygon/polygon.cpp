#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],m;
void ss(int x,int y,int k,int p,int u){
	if(n==k-1){
		return ;
	}
	if(x>y*2&&p>=3&&x!=0&&y!=0&&u!=p){
		m++;
		u=p;
		m%=998244353;
	}
	ss(x+a[k+1],max(y,a[k+1]),k+1,p+1,u);
	ss(x,y,k+1,p,u);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ss(a[1],a[1],1,1,1);
	ss(0,0,1,0,0);
    cout<<m;
	return 0;
} 
