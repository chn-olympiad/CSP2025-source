#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],R,x=1,y=1;
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&f==1)y++,f=0;
		else if(x==1&&f==0)y++,f=1;
		else if(f==1)x++;
		else x--;
	}
	return 0;
}
