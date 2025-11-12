#include<bits/stdc++.h>
using namespace std;

const int NM = 2e2;
int A[NM+4];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>A[i];
	int sr = A[1],id = 0;
	sort(A+1,A+1+n*m,greater<int>());
	for(int i = 1;i <= n*m;i++)
		if(A[i] == sr) {id = i;break;}
	int c = id%(2*n),r = id/(2*n)*2;
	if(id%(2*n) > 0) r += (id%(2*n)>n?2:1);
	if(c == 0) c = 2*n;
	else if(c > n) c = n-(c-n)+1;
	cout<<r<<' '<<c;
	return 0;
}
