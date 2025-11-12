#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=998244353;

int n,m;
int s[514],c[514];
int sa[15];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch; cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		int ans=0;
		for(int i=1;i<=n;i++) sa[i]=i;
		do{
			int res=0,fal=0;
			for(int i=1;i<=n;i++){
				int p=sa[i];
				if(s[i]==0||fal>=c[p]) fal++;
				else res++;
			}
			if(res>=m) ans++;
		}while(next_permutation(sa+1,sa+1+n));
		cout<<ans%mod<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}

