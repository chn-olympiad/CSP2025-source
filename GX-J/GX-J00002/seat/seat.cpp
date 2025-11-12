#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int S,n,m,x;
int g[20][20],a[N],k=1;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum = n*m;
	for(int i = 1;i<=sum;i++){
		cin>>a[i];
	}
	x = a[1];
	sort(a + 1,a+1+sum,cmp);
	for(int i = 1;i<=sum;i++) if(a[i] == x) S = i;
	if(S % 2 == 1){
		if(S % (n - 1) == 0)cout<<S/n + 1<<' '<<S%n+1;
		else cout<<S/n + 1<<' '<<S%n;
	}
	if(S % 2 == 0)cout<<S/n<<' '<<n-S%n;
	return 0;
}
