#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],f,dx[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) dx[i]=dx[n*2-i+1]=i;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f==a[i]){
			int c=i/n+1;
			if(i%n==0) c--;
			int r;
			if(i%(n*2)==0) r=dx[1];
			else r=dx[i%(n*2)];
			cout<<c<<' '<<r;
			return 0;
		}
	}
	return 0;
}
