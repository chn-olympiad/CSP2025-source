#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[114];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1;
	if(a[1]==r){
		cout<<"1 1";
		return 0;
	}
	for(int i=2;i<=n*m;++i){
		if(x%2&&y==n) x++;
		else if(x%2&&y!=n) y++;
		else if(x%2==0&&y==1) x++;
		else y--;
		if(a[i]==r){
			cout<<x<<' '<<y;
			break;
		}
	}
	return 0;
}
