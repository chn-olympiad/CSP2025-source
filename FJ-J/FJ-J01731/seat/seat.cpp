#include<bits/stdc++.h>
using namespace std;
int a[10001],x,y;
int m,n,xb,mx=-1,lkj,xbo;
void dfs(int l,int r,int ds,bool dssj){
//	cout<<l<<" "<<r<<endl;
	if(ds==x){
		cout<<r<<" "<<l;
		return;
	}
	if(dssj==0){
		if(l>=1&&l<n){
			ds++;
			dfs(l+1,r,ds,0);
		}
		else{
			ds++;
			dfs(l,r+1,ds,1);
		}
	}
	else{
		if(l>1&&l<=n){
			ds++;
			dfs(l-1,r,ds,1);
		}
		else{
			ds++;
			dfs(l,r+1,ds,0);
		}
	}
	
	
}
bool cmp(int tx,int ty){
	return tx>ty;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			lkj=a[i];
		} 
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==lkj){
			xbo=i;
		}
	}
	x=xbo-1;
	dfs(1,1,0,0);
	return 0;
}
/*
2 5
90 100 4 3 20 97 98 91 40 50
*/