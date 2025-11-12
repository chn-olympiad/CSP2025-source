#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;
struct node{
	int v,flg;
}a[N];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].flg=0;
	}
	a[1].flg=1;
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].flg){
			cout<<y<<" "<<x;
			break;
		}
		if(y&1){
			x++;
			if(x==n+1){
				x=n,y++;
			}
		}else{
			x--;
			if(x==0){
				x=1,y++;
			}
		}
	}
	return 0;
}

