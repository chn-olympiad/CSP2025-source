#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+1+n*m,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			x--;
			if(x==0){
				if(i%2==1){
					cout<<i<<' '<<j;
				}else{
					cout<<i<<' '<<n+1-j;
				}
			}
		}
	}
	return 0;
}
