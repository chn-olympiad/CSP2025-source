#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m,a[MAXN*MAXN],tmp;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m>>tmp;
	a[1]=tmp;
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==tmp){
			int x,y;
			if (i%n==0) x=n;
			else x=i%n;  //x为行数 
			y=i/m;
			if (i%m!=0) y++;  //y为列数 
			if (y%2==1) cout<<y<<' '<<x;
			else cout<<y<<' '<<n-x+1;
			return 0;
		}
	}
	return 0;
}

// Don't let me AFO pls...QwQ
