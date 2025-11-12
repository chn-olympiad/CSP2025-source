#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int q[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w=0,cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>q[i];
		if(i==1)w=q[i];
		else if(q[i]>w)cnt++;
	}
	int x=cnt/n,y=cnt%n;
	if(y!=0){
		x+=1;
		if(x%2==0)cout<<x<<" "<<n-y+1;
		else cout<<x<<" "<<y;
	}else{
		if(x%2==0)cout<<x<<" "<<1;
		else cout<<x<<" "<<n;
	}
	return 0;
} 
