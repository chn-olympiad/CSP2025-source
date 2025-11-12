#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,m,sc[N];
int solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&sc[i]);
	}
	int Rsc=sc[1];
	sort(sc+1,sc+1+n*m);
	int k=lower_bound(sc+1,sc+1+n*m,Rsc)-sc;
//	printf("%d",k);
	k=n*m-k+1;
	int x=0,y=0;
	if(k%n==0)x=k/n;
	else x=k/n+1;
	if(x%2==1)y=k%n;
	else y=n-k%n+1;
	if(y==0)y=n;
	printf("%d %d",x,y);
	
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
