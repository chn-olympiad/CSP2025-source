#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
int x=0,y=1,a,n,m,R;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		v.push_back(a);
	}
	R=v[0];
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(x==n&&y%2!=0) y++;
		else if(x==1&&y%2==0) y++;
		else if(y%2!=0) x++;
		else x--;
		//cout<<y<<" "<<x<<" "<<v[i]<<endl;
		if(v[i]==R){
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}