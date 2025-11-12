#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,b[20][20];
struct info{
	int c,id;
}a[110];
bool cmp(info x,info y){
	return x.c>y.c;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				++cnt;
				if(a[cnt].id==1){
					cout<<j<<" "<<i<<endl;
					return 0;
				}	
			}
		}
		else{
			for(int i=n;i>=1;i--){
				++cnt;
				if(a[cnt].id==1){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
