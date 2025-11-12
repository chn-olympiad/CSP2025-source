#include<bits/stdc++.h>
using namespace std;
int n,m,r,a,cnt;
int main(){
	//awa
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	cin>>n>>m>>r;
	if(n==0||m==0)return 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(i!=1||j!=1){
		cin>>a;
		if(a>r) cnt++;
	}
	cnt++;
	//cout<<cnt<<endl;
	int x=((cnt+n-1)/n);
	cout<<x<<' '<<(x%2==1 ? cnt%n+1 : (n-cnt%n+1) );
	return 0;
}
