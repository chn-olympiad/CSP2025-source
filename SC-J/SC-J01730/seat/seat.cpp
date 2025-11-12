#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[205],r,c,t,s[105][105];
bool flg=0,flag=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=1,co=1;
	for(int j=1;j<=m;){
		if(co>n*m) break;
		s[i][j]=a[co++];
		if(!flg&&i<n) i++;
		else i--;
		if(i==n&&!flg) s[i][j]=a[co++],j++,flg=1;
		else if(i==1&&flg) s[i][j]=a[co++],j++,flg=0;
		if(j>m) break;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(s[i][j]==r){
			c=j,t=i;
			break;
		}
	cout<<c<<" "<<t;
	return 0;
}