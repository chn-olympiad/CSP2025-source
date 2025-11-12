#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int mod=998244353;

int n,m;
string s;
int c[N];

int ans=1;
void inc(int &x,int y){
	x=(x*y)%mod;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		inc(ans,i);
	}
	cout<<ans;
	return 0;
}
