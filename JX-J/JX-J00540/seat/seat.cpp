//seat
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=10+5;
struct node{
	int pts;
	int id;
};

int n,m;
node a[MAXN*MAXN];

bool cmp(node a,node b){
	return a.pts>b.pts;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#endif
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].pts;
		a[i].id=i;
	}
	
	sort(a+1,a+1+n*m,cmp);
	
	int res=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			res=i;
			break;
		}
	}
//	cout<<res<<emdl;//
	
	int cnt=0;
	int x=0,y=1;
	while(cnt<=res){
		if(cnt==res){
			break;
		}
		if(y%2==1){
			x++;
			if(x>n){
				x=n;
				y++;
			}
		}
		else{
			x--;
			if(x<1){
				x=1;
				y++;
			}
		}
		cnt++;
//		cout<<cnt<<" "<<x<<" "<<y<<emdl;//
	}
	cout<<y<<" "<<x<<emdl;
	
	return 0;
}
