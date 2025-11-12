#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int zb;
}grade[10005];
int n,m,tmp;
bool cmp(node a,node b){
	return a.num>b.num;
}
void operation(int x,int y,int bh,int op){
	if(grade[bh].zb==1){
		cout<<y<<" "<<x;
		return;
	}
	if(x>n&&y>m) return;
	if(op==1){
		if(x+1<=n){
			//cout<<x<<" "<<y<<":"<<bh<<"->"<<grade[bh].num<<'\n';
			operation(x+1,y,bh+1,op);
		}
		if(x+1>n){
			//cout<<x<<" "<<y<<":"<<bh<<"->"<<grade[bh].num<<'\n';
			operation(x,y+1,bh+1,0);
		}
	}
	if(op==0){
		if(x>1){
			//cout<<x<<" "<<y<<":"<<bh<<"->"<<grade[bh].num<<'\n';
			operation(x-1,y,bh+1,op);
		}
		if(x<=1){
			//cout<<x<<" "<<y<<":"<<bh<<"->"<<grade[bh].num<<'\n';
			operation(x,y+1,bh+1,1);
		}
	}
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i].num;
		grade[i].zb=i;
	}
	sort(grade+1,grade+n*m+1,cmp);
	operation(1,1,1,1);
	return 0;
}
//记得关注释！