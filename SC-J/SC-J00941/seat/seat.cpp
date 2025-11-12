#include<bits/stdc++.h>
using namespace std;
const int N=105;

struct node{
	int c,r;
	int num,id;
}a[N];

int n,m;

bool cmd(node a,node b){
	return a.num>b.num;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	int y=1;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	
	sort(a+1,a+n*m+1,cmd);
	
	a[1].c=1,a[1].r=1;
	
	for(int i=2;i<=n*m;i++){
		a[i].c=a[i-1].c;
		a[i].r=a[i-1].r+y;
		if(a[i].r>n){
			a[i].c++;
			a[i].r--;
			y=-1;
		}else if(a[i].r<1){
			a[i].c++;
			a[i].r++;
			y=1;
		}
	}
	
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<a[i].c<<" "<<a[i].r<<'\n';
			break;
		}
	}
	
	return 0;
} 