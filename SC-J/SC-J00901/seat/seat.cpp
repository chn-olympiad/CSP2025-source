#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
#define ll long long
int n,m,g[N],pos;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>g[i];
	int tot=g[1],pos;
	sort(g+1,g+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(tot==g[i])pos=i;
	int lie=((pos-1)/n)+1;
	if(lie%2==1){
		cout<<lie<<' '<<(pos-(lie-1)*n);
	}else{
		cout<<lie<<' '<<n-(pos-(lie-1)*n)+1;
	}
	return 0;
}