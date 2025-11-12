#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int y=(x-1)/n+1;
	if(y%2==1){
		cout<<y<<" "<<x-(y-1)*n;
	}else{
		cout<<y<<" "<<y*n-x+1;
	}
}

