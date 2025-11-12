#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[110],temp,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	temp=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==temp){
			cnt=i;
			break;
		}
	}
	int y=cnt/n,x=cnt%n;
	if(x>0){
		y++;
		if(y%2==0)x=n-x+1;
	}else{
		if(y%2==0)x=1;
		else x=n;
	}
	cout<<y<<" "<<x;
	return 0;
}
