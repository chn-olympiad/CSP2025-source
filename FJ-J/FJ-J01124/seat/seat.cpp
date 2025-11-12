#include<bits/stdc++.h> 
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s){
			s=i;
			break;
		}
	cout<<(s+n-1)/n<<" ";
	if(((s+n-1)/n)%2==0)cout<<(s%n==0?1:n-s%n+1);
	else cout<<(s%n==0?n:s%n);
	return 0;
}
