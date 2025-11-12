#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	while(1){
		if(x==1&&y%2==0){
			y++;
		} else if(x==n&&y%2==1){
			y++;
		} else if(y%2==1){
			x++;
		} else if(y%2==0){
			x--;
		}
		k++;
		if(a[k]==r){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}