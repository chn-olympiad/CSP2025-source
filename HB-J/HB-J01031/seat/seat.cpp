#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],t,u;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(i==1) t=a[i];
	}
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m*n;i++) if(a[i]==t) u=i;
	cout<<(u/m)+1<<" ";
	if((u/m+1)%2==1){
		if(u%m==0) cout<<m;
		else
			cout<<u%m;
	}
	else{
		if(u%m==0) cout<<1;
		else
			cout<<n-(u%m-1);
	}
	return 0;
}
