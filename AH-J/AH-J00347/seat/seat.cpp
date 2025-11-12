#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,k=0,x=0;
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==x){
			int c=(i-1)/n;
			cout<<c+1<<" ";
			if(c&1) cout<<n-i+c*n+1;
			else cout<<i-c*n;
			break;
		}
	}
	return 0;
}
