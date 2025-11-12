#include<bits/stdc++.h>
using namespace std;
struct sss{
	int t,c;
	bool f=0;
}a[105];
bool cmp(sss l,sss r){
	return l.c>r.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w=0,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].t=i;
		if(i==1){
			a[i].f=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].f){
			w=i;
			break;
		}
	}
	if(w%n==0){
		x=w/n;
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}else{
		x=w/n+1;
		w=w%n;
		if(x%2==0){
			y=n-w+1;
		}else{
			y=w;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
