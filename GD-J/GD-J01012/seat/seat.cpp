#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Node{
	ll num,idx;
}a[105];
bool cmp(Node a,Node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].idx=i;	
	}
	sort(a+1,a+1+n*m,cmp);
	ll p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].idx==1){
			p=i;
			break;
		}
	}
	ll x=p%n,y=p/n,l,h;
	if(y%2==0){
		if(x==0){
			h=1;
			l=y;
		}else{
			l=y+1;
			h=x;
		}
	}else{
		if(x==0){
			h=n;
			l=y;
		}else{
			l=y+1;
			h=n-x+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}

