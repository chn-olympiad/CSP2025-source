#include<bits/stdc++.h>
using namespace std;
int n,m,r;
struct nd{
	int k,u;
}a[105];
bool cmp(nd wq,nd qw){
	return wq.k>qw.k;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		int g;
		cin>>g;
		a[i].k=g;
		a[i].u=i;
	}
	r=a[1].u;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].u==r){
			r=i;
			break;
		}
	}
	int x=1,y=1,head=1;
	for(int i=2;i<=r;i++){
		if(head==1){
			y++;
			if(y==m){
				head=2;
			}
		}else if(head==2){
			x++;
			head=3;
		}else if(head==3){
			y--;
			if(y==1){
				head=4;
			}
		}else if(head==4){
			x++;
			head=1;
		}
	}
	
	cout<<x<<' '<<y;
	return 0;

}
