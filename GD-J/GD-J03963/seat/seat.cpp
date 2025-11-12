#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=105;

int a[N];
int n,m;

bool cmp(int a,int b){
	return a>b;
}

pair<int,int>f(int x,int y,int k,int a){
	if(k==1){
		return{y,x};
	}
	else{
		if(x+a<=n&&x+a>=1){
			return f(x+a,y,k-1,a);
		}
		else{
			return f(x,y+1,k-1,-a);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	pair<int,int>s=f(1,1,r,1);
	cout<<s.first<<" "<<s.second;
	return 0;
}
