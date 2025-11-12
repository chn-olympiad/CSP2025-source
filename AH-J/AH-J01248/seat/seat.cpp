#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int tmp,x,y,pos,f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tmp=a[1],x=1,y=0,pos=0;
	sort(a+1,a+1+n*m,cmp);
	while(1){
		if(!f)y++;
		else y--;
		pos++;
		if(y==n+1)y=n,f=1,x++;
		if(y==0)y=1,f=0,x++;
		if(a[pos]==tmp){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
