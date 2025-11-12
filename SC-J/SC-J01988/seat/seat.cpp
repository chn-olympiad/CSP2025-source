#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],fs,x[105],y[105];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	fs=a[1];
	sort(a+1,a+n*m+1,cmp);
	x[1]=1,y[1]=1;
	for(int i=2;i<=n*m;i++){
		if(y[i-1]!=m&&x[i-1]%2==1){
			x[i]=x[i-1];
			y[i]=y[i-1]+1;
		}else if(y[i-1]!=1&&x[i-1]%2==0){
			x[i]=x[i-1];
			y[i]=y[i-1]-1;
		}else{
			x[i]=x[i-1]+1;
			if(x[i]%2==1){
				y[i]=1;
			}else{
				y[i]=m;
			}
		}
		if(a[i]==fs){
			cout<<x[i]<<" "<<y[i];
		}
	}
	return 0;
}
