#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int n,m;
struct node{
	int id,score;
}a[MAXN];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			break;
		}
		if(y%2==1&&x==n){
			y++; 
		}else if(y%2==0&&x==1){
			y++;
		}else{
			if(y%2)x++;
			else x--;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
