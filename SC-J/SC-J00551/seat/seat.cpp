#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m;
struct node{
	int val,ID;
	node(int val=0,int ID=0):val(val),ID(ID){}
	bool operator<(const node &tmp)const{
		return val>tmp.val;
	}
}a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;a[i].ID=i;
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i].ID==1){
			int qw=(i-1)/(n)+1,op=(i-1)%(n)+1;
			if(qw%2==1){
				cout<<qw<<" "<<op;
			}
			else{
				cout<<qw<<" "<<n-op+1;
			}
			return 0;
		}
	}
	return 0;
}