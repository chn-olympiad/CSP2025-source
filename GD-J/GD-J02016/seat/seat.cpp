#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int x,int y){
	if(x>y)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int c,r;
	if(x%n==0)c=x/n;
	else c=x/n+1;
	int q=x%n;
	if(c%2==0&&q==0)r=1;
	else if(c%2!=0&&q==0)r=n;
	else if(c%2==0&&q!=0)r=n-q+1;
	else if(c%2!=0&&q!=0)r=q;
	cout<<c<<" "<<r;
	return 0;
}
