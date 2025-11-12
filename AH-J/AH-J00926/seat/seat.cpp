#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	int x=R/n,y=R%n;
	if(x%2==1){
		if(y==0){cout<<x<<" "<<n;}
		else{cout<<x+1<<" "<<n-y+1;}
	}else{
		if(y==0){cout<<x<<" "<<1;}
		else{cout<<x+1<<" "<<y;}
	}
	return 0;
}
