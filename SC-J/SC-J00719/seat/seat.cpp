#include<bits/stdc++.h>
using namespace std;
int n,m,gd;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	gd = a[1];
	sort(a+1,a+1+n*m,cmp);
	int l;
	for(int i=1;i<=n*m;i++){
		if(a[i]==gd){
			l = i;
			break;
		}
	}
	int x,y = l/m;
	if(l%m!=0) y++;
	if(y%2==1){
		int k = l%n;
		if(k==0) k = n;
		x = k;
	}else{
		int k = l%n;
		if(k==0) k = n;
		x = n-k+1;
	}
	cout<<y<<" "<<x;
}