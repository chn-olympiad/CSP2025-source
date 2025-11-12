#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],k,r,fl,x,y;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j];
		}
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k=i;
			break;
		}
	}
	k--;//the k-- cost me 5 mins:|
	x=1,y=1;
	while(k--){
		if(fl==0){
			if(y==n){
				x++;
				fl=1;
			}else{
				y++;
			}
		}else{
			if(y==1){
				x++;
				fl=0;
			}else{
				y--;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}//written by zsz0804_/GD-J00722
