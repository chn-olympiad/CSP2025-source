#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N*N],mp[N][N],n,m,x,k,c,r;
bool cmp(int l,int r){return l>r;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			k=i;
			break;
		}
	c=(k-1)/n+1;
	r=(k-1)%n+1;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r;
    return 0;
}
