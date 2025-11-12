//I Love CCF
//Accepted!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
using namespace std;
struct node{
	int val,id;
};
int n,m;
node a[105];
bool cmp(const node& x,const node& y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n*m){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=0;
	rep(i,1,n*m){
		if(ny&1){
			if(nx<n)++nx;
			else if(nx==n)++ny;
		}else{
			if(nx>1)--nx;
			else if(nx==1)++ny;
		}
		if(a[i].id==1){
			printf("%d %d\n",ny,nx);
			return 0;
		}
	}
	return 0;
}
//I Love CCF 
