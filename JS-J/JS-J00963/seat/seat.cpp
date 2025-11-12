#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[101];
long long b;
bool cmp(int x,int y){
	return x>y;
}
int dg(int x,int y,int cnt,int h){
	if(a[cnt]==b){
		cout<<y<<" "<<x;
	}
	else{
		if(x==n&&h==1){
			dg(x,y+1,cnt+1,-1);
		}
		else if(x==1&&h==-1){
			dg(x,y+1,cnt+1,1);
		}
		else{
			dg(x+h,y,cnt+1,h);
		}
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	dg(1,1,1,1);
	return 0;
}
