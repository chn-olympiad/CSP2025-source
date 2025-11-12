#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int s;
	int f;
}a[1010];
int cmp(node c,node d){
	return c.f>d.f;
}
int gx,gy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].s==1){
			gy=i;
		}
	}
	while(gy>n){
		gx++;
		gy-=n;
	}
	if(gx%2==0){
		cout<<gx+1<<" "<<gy;
	}else if(gx%2==1){
		cout<<gx+1<<" "<<n-gy+1;
	}
	cout<<endl;
	return 0;
}
