#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a,b;
}f[1000005];
bool cmp(node a,node b){
	return a.a>b.a;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i].a;
		f[i].b=i;
	}
	sort(f+1,f+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(f[cnt].b==1){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(f[cnt].b==1){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
*/