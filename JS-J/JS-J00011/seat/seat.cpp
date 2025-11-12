#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[105];
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
	int R=a[1],w;
	stable_sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			w=i;
		}
	}
	int c,r;
	if(w%n==0){
		c=w/n;
		if(c%2==0){
			r=1;
		}else{
			r=n;
		}
	}else{
		c=w/n+1;
		if(c%2==0){
			r=n-(w%n)+1;
		}else{
			r=w%n;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
