#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N],k=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) k++;
	}
	int x=1,y=1,pt=1,now=1;
	while(now<k){
		if(pt==1&&y==n){
			x++;
			pt=-1;
		}else if(pt==-1&&y==1){
			x++;
			pt=1;
		}else{
			y+=pt;
		}
		now++;
	}
	cout<<x<<' '<<y;
	return 0;
}