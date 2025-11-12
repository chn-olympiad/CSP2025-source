#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e2+10;
int n,m,a[N]; 
int mod(int a,int b){
	while(a>b)a-=b;
	return a;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		int ma=a[1],id=1;
		cnt++;
		for(int j=2;j<=n*m;j++){
			if(ma<a[j]){
				ma=a[j];id=j;
			}
		}
		a[id]=-1e9;
		if(id==1)break;
	}
	int x=int(cnt*1.0/n+0.9999),y;
	if(x%2==1)y=mod(cnt,n);
	else y=m-cnt%n;
	cout<<x<<' '<<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int _=1;//cin>>_;
	while(_--)solve();
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
