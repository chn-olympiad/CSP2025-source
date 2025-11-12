#include<bits/stdc++.h>
using namespace std;
int a[106];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x,y,s,R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			s=i;
			break;
		}
	}
	y=ceil(s*1.0/n);
	if(y%2==1){
		x=s%n;
		if(s%n==0){
			x=n;
		}
	}else{
		int t=(s%n==0)?n:s%n;
		x=n+1-t;
	}
	cout<<y<<' '<<x;
	return 0;
} 