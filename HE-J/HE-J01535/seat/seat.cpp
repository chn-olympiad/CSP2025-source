#include<bits/stdc++.h>
using namespace std;
int n,m,now,xx,yy;
int a[110];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	now=a[1];
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=num;i++) if(now==a[i]){now=i; break;}
	if(now%n==0) yy=now/n;
	else yy=now/n+1;
	if(yy%2==0){
		if(now%n==0) xx=1;
		else xx=n-(now%n)+1;
	}else{
		if(now%n==0) xx=n;
		else xx=now%n;
	}
	cout<<yy<<" "<<xx; 
	return 0;
} 
