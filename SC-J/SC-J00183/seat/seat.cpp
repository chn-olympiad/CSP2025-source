#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
int A[104],n,m,a;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	REP(z,1,n*m)cin>>A[z];
	a=A[1];
	sort(A+1,A+1+n*m,greater<int>());
	REP(z,1,n*m)if(a==A[z]){
		a=z;
		break;
	}
	if(((a-1)/n+1)%2==1)cout<<(a-1)/n+1<<' '<<(a-1)%n+1;
	else cout<<(a-1)/n+1<<' '<<n-(a-1)%n;
	return 0;
}