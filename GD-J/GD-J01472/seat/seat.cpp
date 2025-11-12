#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int val,index;
}a[2000];
bool cmp(edge x,edge y){
	return x.val>y.val;
}
int b=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].index=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].index==1){
			break;
		}
		if(b==0){
			y++;
			if(y>n){
				x++;
				b=1;
				y--;
			}
		}else{
			y--;
			if(y<1){
				x++;
				b=0;
				y++;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
