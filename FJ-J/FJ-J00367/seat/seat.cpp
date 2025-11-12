#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	//cout<<p<<endl;
	int c=(p%n==0?p/n:p/n+1);
	int r=(c%2==1?p-(c-1)*n:n+1-p+(c-1)*n);
	cout<<c<<" "<<r<<endl;
	return 0;
}

