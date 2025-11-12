#include<bits/stdc++.h>
using namespace std;
bool sttt;
int n,m,rnk;
int a[200];
bool eddd;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n*m;i++) if(a[i]>=a[1]) rnk++;
	int ln=rnk/(2*n)*2,lft=0;rnk%=2*n;
	if(rnk==0) rnk=2*n,ln-=2;
	if(rnk>n) ln+=2,lft=2*n-rnk+1;
	else ln++,lft=rnk;
	cout<<ln<<" "<<lft<<"\n";
	cerr<<(&eddd-&sttt)*1.0/1024/1024<<"\n";
	return 0;
}
