#include<bits/stdc++.h>
using namespace std;

int n,m;

bool cmp(int a,int b){
	return a>b;
}

int ans[111][111];

int arr[1111];

int mine;

int x=1,y=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	mine=arr[0];
	sort(arr,arr+(n*m),cmp);
	for(int i=0;i<n*m;i++){
		ans[x][y]=arr[i];
		if(y%2==1){
			x++;
			if(x>n){
				x=n;
				y++;
			}
		}else{
			x--;
			if(x<1){
				x=1;
				y++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==mine){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
