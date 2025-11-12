#include<bits/stdc++.h>
using namespace std;
int p,q,n,m,i,z;
struct pcs{
	int x,y;
}a[1010];
bool cmp(pcs f,pcs b){
	return f.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i].x;
		if(i==1) a[i].y=1;
	}
	sort(a+1,a+1+n*m,cmp);
	p=q=1;z=1;
	for(i=1;i<=n*m;i++){
		if(a[i].y==1) {
			cout<<p<<" "<<q;
			return 0;
		}
		q+=z;
		if(q<=0||q>n){
			q-=z;
			p++;
			z=-z;
		}
	}
	return 0;
}

