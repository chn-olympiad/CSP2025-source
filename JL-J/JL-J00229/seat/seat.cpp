#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
int a[N];
bool cmp(int i,int j){return i>j;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,cnt=1;
	cin>>n>>m>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0])cnt++;
	}
	int c=cnt/n,r=cnt%n;
	if(r==0){
		if(c%2==1)r=n;
		else r=1;
	}
	else{
		c++;
		if(c%2==0)r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
