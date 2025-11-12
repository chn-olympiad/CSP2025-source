#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define ll long long
const int N=5e3+5,Mod=998244353;
int n,m,c[N];
bool s[N];
int p[N];
void work1(){
	ll ans=0;
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		if(ans>=Mod) ans-=Mod;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[p[i]]||!s[i]){
				sum++;
				continue;
			}if(i-sum>=m){
				ans++;
				break;
			}
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c1;
		cin>>c1;
		s[i]=c1-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	work1(); 
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
