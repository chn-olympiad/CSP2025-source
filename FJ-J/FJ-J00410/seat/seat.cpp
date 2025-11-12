#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[15][15],l[105];
int mc,c,r;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++)
		cin>>l[i];
	l[1] = a1;
	sort(l+1,l+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(l[i]==a1) mc = i;
	}
	int ys = mc%n;
	c = mc/n;
	if(c%2==0){
		r = ys;
		if(ys!=0) c+=1;
		else r+=1;
	}else{
		r = n-ys+1;
		if(ys!=0) c+=1;
		else r-=1;
	}
	cout<<c<<' '<<r;
	return 0;
}
