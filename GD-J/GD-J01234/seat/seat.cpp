#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,p[N],x,y;
inline bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n*m;++i)
		cin >>p[i];
	sort(p+2,p+2+n*m,cmp);
	int i;
	for (i=2;i<=n*m&&p[i]>p[1];++i){}
	--i;
	int k=(i-1)/n+1;
	if (k%2==1){
		cout <<k<<' '<<(i-1)%n+1;
	}
	else{
		cout <<k<<' '<<n-((i-1)%n);
	}
	return 0;
}
