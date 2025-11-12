#include<bits/stdc++.h>
#define int long long
using namespace std;
void init(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int n,m,whe,num;
int x[101];
int a[11][11];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	init();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	num=x[1];
	sort(x+1,x+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x[i]==num){
			whe=i;
			break;
		}
	}
	int l=ceil(whe*1.0/n);
	cout<<l<<" ";
	int r=whe-(l-1)*m;
	if(l%2==0){
		cout<<n-r+1;
	}
	else{
		cout<<r;
	}
	return 0;
} 
