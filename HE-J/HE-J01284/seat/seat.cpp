#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,r,posi=1,posj=1;
int a[205];
int ans[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt];
			cnt++;
		}
	}
	r=a[1];
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++){
		ans[posi][posj]=a[i];
		if((posi==n&&posj%2==1)||(posi==1&&posj%2==0)){
			posj++;
		}else{
			if(posj%2==0){
				posi--;
			}else posi++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
} 
