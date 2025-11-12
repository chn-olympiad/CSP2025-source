#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+100;
int n,m;
int a[N],ans;
int step=0,cnt=1,go=-1,op=n;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	op=n;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==1) step++,go=0-go,op=n-op+1,cnt=op;
		if(a[i]==ans){
			cout<<step<<" "<<cnt;
			break;
		}
		cnt+=go;
	}
	return 0;
}
