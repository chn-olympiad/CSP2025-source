#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,f[1005],x=1,y=1;
bool cmp(int _x,int _y){return _x>_y;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>f[i];
	int R=f[1];
	sort(f+1,f+n*m+1,cmp);
	int k=0;
	for(k=1;k<=n*m;++k)if(R==f[k])break;
	k--;
	while(k--){
		if(x%2!=0&&y<n)y++;
		else if(x%2==0&&y>1)y--;
		else x++;
	}
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 97 98
1 2

2 2
98 99 100 97
2 2

3 3
94 95 96 97 98 99 100 93 92
3 1
*/