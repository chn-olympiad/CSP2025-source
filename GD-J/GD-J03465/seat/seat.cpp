#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],k,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			k=i;
			break;
		}
	}
	y=(k+m-1)/m;
	if(y&1){
		x=k-(y-1)*m;
	}else{
		int xx=k-(y-1)*m;
		x=m-xx+1;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}

