#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
char s[N];
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') f=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(f){
		int ans=1;
		for(int i=1;i<=n;i++) ans*=i;
		cout<<ans;
		return 0; 
	}
	return 0;
}

