#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t;
int x=0,y=1;
bool ok=0,f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(f){
			y++;
			f=0;
		}
		else if(ok==0){
			x++;
			if(x==n) ok=1,f=1;
		}
		else{
			x--;
			if(x==1) ok=0,f=1;
		}
		if(a[i]==t) break;
	}
	cout<<y<<" "<<x;
	return 0;
}
