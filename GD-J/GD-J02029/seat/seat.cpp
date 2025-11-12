#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,i;
}a[101];
int n,m;
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			x=i;
			break;
		}
	}
	int l=2*(x/(2*m));
	int h;
	x=x%(2*m);
	if(x==0){
		h=1;
	}else if(x<=m){
		l++;
		h=x;
	}else{
		l+=2;
		h=2*m-x+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

