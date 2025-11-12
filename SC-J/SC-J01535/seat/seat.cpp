#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int id,w;
}a[N];
bool cmp(node a,node b){
	return a.w>b.w;
}
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int tot=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++tot].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++tot].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
	}

