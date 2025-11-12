#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=202;
int n,m;
int a[N];
bool cmp(int x,int y){return x>y;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int res=a[1],pos=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==res){pos=i;break;}
	int c=(pos+n-1)/n,r=pos-(c-1)*n;
	(!(c&1))&&(r=n-r+1);
	cout<<c<<' '<<r<<'\n';
	return 0;
}

