#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[205];
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
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			break;
		}
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
