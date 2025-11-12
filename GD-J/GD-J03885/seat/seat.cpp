#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e2+5;
const int INF=0x3f3f3f3f;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			k=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<y<<" "<<x<<endl;
		}
		int p=((i-1)/n);
		if(p%2==0){
			if(x+1>n){
				y++;
			}else{
				x++;
			}
		}else{
			if(x-1<1){
				y++;
			}else{
				x--;
			}
		}
	}
	return 0;
}

