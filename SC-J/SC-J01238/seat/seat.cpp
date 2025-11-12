#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[1010];
bool cmp(int x,int y){
	return y<x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	int o=n*m;
	sort(a+1,a+o+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	int x=1,y=1,p=0;
	for(int i=2;i<=cnt;i++){
		if(x%2==1){
			p=1;
		} else{
			p=-1;
		}
		if(y==n&&x%2==1){
			x++;
		} else if(y==1&&x%2==0){
			x++;
		} else{
			y+=p;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}