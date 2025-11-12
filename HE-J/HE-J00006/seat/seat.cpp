#include <bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,p;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1<<endl;
		return 0; 
	}
	p = a[1][1];
	//sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==p){
				if(j==1){
					cout<<1<<" "<<i<<endl;
				} 
			}
		}
	}
	return 0;
}
