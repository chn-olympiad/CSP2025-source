#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=100;
int s[N*N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int tmp=s[1];
	int idx;
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==tmp){
			idx=i;
			break;
		}
	}
	if(idx%n==0) cout<<idx/n<<" ";
	else cout<<idx/n+1<<" ";
	if((idx/n)&1){
		if(idx%n==0) cout<<m;
		else 
		cout<<m-idx%n+1;
	}else{
		if(idx%n==0) cout<<1;
		else
		cout<<idx%n;
	}
	return 0;
}
