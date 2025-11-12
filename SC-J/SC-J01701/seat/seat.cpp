#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,a[2010],pos,k;
struct node{
	int r,c;
}b[2010];
int main(){
	ios
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				b[(i-1)*n+j].r=j,b[(i-1)*n+j].c=i;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[(i-1)*n+n-j+1].r=j,b[(i-1)*n+n-j+1].c=i;
			}
		}
	}
	cout<<b[pos].c<<" "<<b[pos].r;
	return 0;
}
