#include<bits/stdc++.h>
using namespace std;
int n,m,tol,x=1,y=1,k=1;
struct node{
	int p,num;
}a[1000];
bool cmp(node a1,node a2){
	return a1.num>a2.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tol=n*m;
	for(int i=1;i<=tol;i++){
		cin>>a[i].num;
		a[i].p=i;
	}
	sort(a+1,a+tol+1,cmp);
	while(a[k].p!=1){
		k++;
		if(x==n&&y%2==1){
			y++;
		}else if(x==1&&y%2==0){
			y++;
		}else{
			if(y%2==0){
				x--;
			}else{
				x++;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
