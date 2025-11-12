#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x;
int a[10101];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			x=i;
			break;
		}
	}
	if((x/n)%2==0&&x%n!=0){
		cout<<(x/n)+1<<" "<<x%n;
	}else if((x/n)%2==1&&x%n==0){
		cout<<(x/n)<<" "<<n;
	}
	else if((x/n)%2==1&&x%n!=0){
		cout<<(x/n)+1<<" "<<(1+n-(x%n));
	}
	else if((x/n)%2==0&&x%n==0){
		cout<<(x/n)<<" "<<1;
	}
	return 0;
}
