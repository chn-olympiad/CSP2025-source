#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=105;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int now=a[1];
	sort(a+1,a+n*m+1);reverse(a+1,a+n*m+1);
	int x=1,y=1,o=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==now){
			cout<<y<<" "<<x<<'\n';
			return 0;
		}
		x+=o;
		if(x<1) x=1,y++,o=1;
		else if(x>n) x=n,y++,o=-1;
	}
	return 0; 
}
