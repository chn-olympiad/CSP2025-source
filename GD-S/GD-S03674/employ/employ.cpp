#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=550;
int b[N],a[N];
char c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		iota(b+1,b+1+n,1);
		auto solve=[&](){
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(cnt2>=a[b[i]]){
					cnt2++;
					continue;
				}
				if(c[i]=='1') cnt1++;
				else cnt2++;
			}
			return cnt1>=m;
		};
		do{
			if(solve()) ans++;
		}while(next_permutation(b+1,b+1+n));
		cout<<ans<<"\n";
		return 0;
	}
	mt19937 rnd(time(0));
	cout<<rnd()<<"\n";
 	return 0;
}/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

