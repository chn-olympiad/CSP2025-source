#include<bits/stdc++.h>
using namespace std;
int n,m,r,ans_x,ans_y;
struct node{
	int num,id;
}a[1500];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			r=i;
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				r--;
				if(r==0){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				r--;
				if(r==0){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 