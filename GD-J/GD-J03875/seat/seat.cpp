#include<bits/stdc++.h>

using namespace std;
struct Node{
	bool id;
	int num;
};
bool cmp(Node x,Node y){
	return x.num>y.num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<Node> a(n*m+1);
	for(int i=0;i<n*m;i++){
		cin>>a[i].num;
		if(i==0) a[i].id=1;
		else a[i].id=0;
	}
	sort(a.begin(),a.begin()+n*m,cmp);
	int rank;
	for(int i=0;i<=n*m;i++){
		if(a[i].id){
			rank=i;
			break;
		}
	}
	int dir=1,Rn=1,Rm=1;
	for(int i=0;i<rank;i++){
		if((i+1)%n==0){
			Rm++;
			dir=0-dir;
		}
		else Rn+=dir;
	}
	cout<<Rm<<' '<<Rn<<endl;
	return 0;
}
