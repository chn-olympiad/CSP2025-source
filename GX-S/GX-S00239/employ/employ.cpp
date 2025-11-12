#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int c[505];
void sov(int x){
	long long ans=1;
	for(int i=x-1;i>0;--i){
		ans=ans*i;
		ans=ans%MOD;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+n+1);
	if(m==1){
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				for(int j=1;j<=n;++j){
					if(c[j]>=j-1 and c[j]>=i){
						sov(n-j+1);
						return 0;
					}
				}
			}
		}
	}
	return 0;

}
