#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,n,m;
	cin >> x >> y;
	n=x*y;
	for(int i=1;i<=n;i++) cin >> a[i];
	m=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==m){
			m=i;
			break;
		}
	}
	if(m%x!=0){
		cout << m/x+1 << ' ';
		if((m/x+1)%2==1) cout << m%x;
		else cout << x-m%x+1;
	}else{
		cout << m/x << ' ';
		if((m/x)%2==1) cout << x;
		else cout << 1;
	}
	return 0;
}
