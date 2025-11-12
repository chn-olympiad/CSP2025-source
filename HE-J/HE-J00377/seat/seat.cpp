#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int fen[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,ans=1;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>fen[i];
	}
	int ming=fen[1];
	sort(fen+1,fen+(m*n)+1,cmp);
    for(int i=1;i<=m;i++){
    	if(i%2==1){
    		for(int j=1;j<=n;j++){
    		    a[j][i]=fen[ans];
    		    ans++;
		    }
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[j][i]=fen[ans];
				ans++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]==ming){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
