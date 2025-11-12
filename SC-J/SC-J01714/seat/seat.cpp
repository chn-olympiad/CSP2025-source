#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int fen[110],id=0;
int arr[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	int a=fen[1];
	sort(fen+1,fen+1+n*m);
	int h=1,l=1;
	bool k=0;
	for(int i=n*m;i>=1;i--){
		if(k==0){
			arr[h][l]=fen[i];
			h+=1;
			if(h>n){
				h-=1;
				l++;
				k=1;
			}
		}else if(k==1){
			arr[h][l]=fen[i];
			h-=1;
			if(h<1){
				h=1;
				l++;
				k=0;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==a){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}