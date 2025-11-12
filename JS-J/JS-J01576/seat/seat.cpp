#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10010],l;
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
	l=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			l=i;
			break;
		}
	}
	int q=l%n;
	int p=(l-q)/n;
	
	if(p%2==0){
		if(l==n*m) cout<<m<<" "<<1;
		else cout<<p+1<<" "<<q;
	}
	else if(p%2==1){
		if(l==n*m) cout<<m<<" "<<n;
		else cout<<p+1<<" "<<n-q+1;
	}
	return 0;
}
