#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int a[10005];
bool cmp(int ax,int bx){
	return(ax>bx);
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pm=1,pn=1;
	bool op=true;
	//int tmp[105][105];
	for(int i=1;i<=m*n;i++){
		//tmp[pn][pm]=a[i];
		if(a[i]==k) cout<<pm<<" "<<pn<<endl;
		if(op){
			if(pn==n){
				pm++;
				op=false;
			}
			else pn++;
		}else{
			if(pn==1){
				pm++;
				op=true;
			}
			else pn--;
		}
		//cout<<a[i];
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<tmp[i][j]<<(tmp[i][j]==k?"* ":" ");
		}
		cout<<endl;
	}*/
	return 0;
}
