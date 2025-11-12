#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> a[i];
	int R=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			p=i;break;
		}
	}
	int c,r;
	if(p%m>0)c=p/m+1;
	else c=p/m;
	if(c%2==1){
		if(p%n==0)r=n;
		else r=p%n;
	}
	else{
		if(p%n==0)r=1;
		else r=n-(p%n)+1;
	}
	cout << c <<" "<<r; 
	return 0;
}
