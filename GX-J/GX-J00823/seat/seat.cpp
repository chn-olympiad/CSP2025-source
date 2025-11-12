#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
struct node{
	int score,id;
};
node a[N]={};
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	int t=1;
	int y=1;
	int lasti=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(lasti==i){
				if(i%2==0){
					y--;
				}else{
					y++;
				}
			}
			if(a[t].id==1){
				cout<<i<<' '<<y;return 0;
			}
			t++;lasti=i;
		}
	}
	return 0;
}
