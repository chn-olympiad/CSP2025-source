#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,k;
int a[500005];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin); freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool spb_f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) spb_f=0;
	}
	if(spb_f){
		int ans=0;
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]) cnt++;
				else{
					ans+=cnt/2+1;
					cnt=0;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
		}
		cout<<ans<<endl;
		return 0; 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int p=i,res=0;
		while(p<=n){
			int tmp=a[p];
			while(p<=n&&tmp!=k) tmp^=a[++p];
			if(tmp==k) res++;
			p++;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

//==============================T3==============================//
// xiang jin CSP-J/S2025 mi huo xing wei da shang
// freopen("number.in","r",stdin)
// freopen("number.in","w",stdin)
// freopen("number.out","r",stdout)
// freopen("number4.in","r",stdin)
// int mian
// itn nit
//==============================================================//
// my luogu uid is 693282 please guan zhu me
// I want to AFO because of whk and PE
// but I want to get a good score in CSP-J/S2025
// maybe I should AFO if I get <1= on CSP-J or <2= on CSP-S
//==============================================================//
// gu fen: 100+100+30+64=294
//==============================================================//
