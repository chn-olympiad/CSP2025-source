#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{int da,id;}a[105];
bool cmp(node x,node y){return x.da>y.da;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].da;
		if(i==1) a[i].id=1;
	}
	int tot=n*m;
	sort(a+1,a+tot+1,cmp);
	int x=0,y=1,cnt=1;
	while(cnt<=tot){
		if(y&1){
			for(x=1;x<=n;x++,cnt++){
//				cout<<y<<' '<<x<<'\n';
//				cout<<cnt<<'\n';
				if(a[cnt].id){
					cout<<y<<' '<<x;
					return 0;
				}
			}
//			cout<<cnt<<'\n';
			y++;
		}
		else {
			for(x=n;x>=1;x--,cnt++){
//				cout<<y<<' '<<x<<'\n';
//				cout<<cnt<<'\n';
				if(a[cnt].id){
					cout<<y<<' '<<x;
					return 0;
				}
			}
			y++;
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
