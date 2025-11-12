#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int a[N],n,m,x; 

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			x=i;
			break;
		}
	int lie=(x-1)/n+1;
	int hang=x%n;
	if(hang==0) hang=n;
	if(lie%2==0) hang=n-hang+1;
	cout<<lie<<" "<<hang;
	return 0; 
}
