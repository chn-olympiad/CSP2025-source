#include<bits/stdc++.h>

#define ll long long
#define rui /*register unsigned*/ int
#define ris(x,y,z) for(rui x=y;x<y+1;++x)
#define ful(x,y,z) for(rui x=y;x>y-1;--x)
#define db double

using namespace std;

const ll N=501;

ll n,m,c[N];

char s[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ll minn=2;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]-='0';
		minn=min(minn,int(s[i]));
		//cout<<int(s[i])<<endl;
	}
	if(minn==1){
		ll res=1;
		for(int i=1;i<=n;++i){
			res=(res*i)%998244353;
		}
		cout<<res;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	return 0;
}
