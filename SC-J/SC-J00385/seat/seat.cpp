#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m,x;
struct node{
	int score,id;
}a[N];
bool cmp(node x,node y){
	return x.score>y.score;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i].score;
    	a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			x=i;
			break;
		}
	}
	int z=x/n;
	if(x%n==0){
		if(z%2==0){
			cout<<x/n<<" "<<1;
		}else{
			cout<<x/n<<" "<<n;
		}
	}else{
		if(z%2==0){
			cout<<x/n+1<<" "<<x-x/n*n;
		}else{
			cout<<x/n+1<<" "<<n-(x-x/n*n)+1;
		}
	}
	return 0;
}