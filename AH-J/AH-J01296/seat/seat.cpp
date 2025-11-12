#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,pos;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	sort(a+1,a+n*m+1);
	int k=lower_bound(a+1,a+n*m+1,pos)-a;
	k=n*m-k+1;
	int ansl=(k+n-1)/n,ansr=k%n;
	if(ansr==0)ansr=n;
	if(ansl%2==0)ansr=n-ansr+1;
	cout<<ansl<<' '<<ansr<<endl;
	return 0;
}
//miaole
