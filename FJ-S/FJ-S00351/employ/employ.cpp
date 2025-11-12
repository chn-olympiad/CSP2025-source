#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=1005;
const ll M=998244353; 
int m,n;
string s;
int c[N],p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int l=s.size();
	for(int i=0;i<l;i++){
		p[i]=i+1;
	}
	ll ans=0;
	if(n<=20){
		do{
		//	for(int i=0;i<l;i++) cout<<p[i]<<" ";
		//	cout<<endl;
			ll fal=0,suc=0;
			for(int i=0;i<l;i++){
				if(s[i]=='0'||fal>=c[p[i]]) {
					fal++;
					continue;
				}
				suc++;
				if(suc>=m) {
					ans++;
					break;
				}
			}
		}while(next_permutation(p,p+l));
		cout<<ans<<endl;
		return 0;
	} 
	ans=1;
	int yuki=n;
	for(int i=1;i<=n;i++) {
		if(c[i]==0) yuki--;
	}
	for(int i=2;i<=yuki;i++){
		ans=((ans%M)*(i%M))%M;
	}
	cout<<ans<<endl;
	return 0;
} 





