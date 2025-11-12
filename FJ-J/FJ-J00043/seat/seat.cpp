#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N],b[30][30];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],s,tmp=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
			break;
		}
	}
	int c,r;
	if(s%n==0){
		c=s/n;
		if(c%2==1){
			r=n;
		}else if(c%2==0){
			r=1;
		}
	}else{
		c=s/n+1;
		if(c%2==1){
			r=s%n;
		}else if(c%2==0){
			r=n-s%n+1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
