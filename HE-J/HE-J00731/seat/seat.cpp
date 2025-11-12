#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6;
struct node{
	int num;
    bool live;
};
node a[N];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].live=false;
	}
	a[1].live=true;
	sort(a+1,a+1+n*m,cmp);
	ll x=1,y=0;
	bool look_up=false;
	for(ll i=1;i<=n*m;i++){
		if(look_up==false){
			y++;
		}else{
			y--;
		}
		if(y<=0){
			y=1;
			x+=1;
			look_up=false;
		}
		if(y>n){
			y=n;
			x+=1;
			look_up=true;
		}
		if(a[i].live==true){
			break;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
