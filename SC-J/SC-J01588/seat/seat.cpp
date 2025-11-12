#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M=1e2+5;
int n,m;
struct abc{
	int u,c;
}a[M];
bool cmp(abc x,abc y){
	return x.c>y.c;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].u=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(i=1;i<=n*m;i++) if(a[i].u==1) break;
	int temp=0;
	i%m!=0?temp=i/m+1:temp=i/m;
	if(temp%2==0){
		cout<<temp<<" ";
		if(i%m==0) cout<<1;
		else cout<<n-i%m+1;
	}
	else if(temp%2!=0){
		cout<<temp<<" ";
		if(i%m==0) cout<<n;
		else cout<<i%m;
	}
	return 0;
}
