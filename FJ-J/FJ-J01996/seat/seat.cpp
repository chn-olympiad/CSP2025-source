#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int u;
	int p=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)u=a[i];
		if(a[i]>u){
			p++;
		}
	}
	int x;
	int y=p/n;
	if(p%n>0)y+=1;
	int j=p%n;
	if(j==0)j=n;
	if(y%2!=0){
		x=j;
	}else{
		x=n+1-j;
	}
	cout<<y<<" "<<x;
	return 0;
}
