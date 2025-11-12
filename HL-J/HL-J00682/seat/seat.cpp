#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int fen[101];
bool cmp(int x,int y){
	if(fen[x]>fen[y]){
		return false;
	}else if(fen[x]<fen[y]){
		return true;
    }
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	int a=fen[1];
	sort(fen+1,fen+n*m+1,cmp);
    if(n==1 && m==1){
    	cout<<1<<" "<<1;
    	return 0;
	}
	if(n==1){
		for(int i=1;i<=m;i++){
			if(fen[i]=a){
				cout<<1<<" "<<i;
			}
		}
	}
	return 0;
}
