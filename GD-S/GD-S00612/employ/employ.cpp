#include<bits/stdc++.h>
#define MOD=998244353
using namespace std;
int n,m,c[100005];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=n;
	if(m==1){
		for(int i=0;i<n;i++){
			if(s[i]=='1')
				for(int j=1;j<=n;j++){
					if(c[j]<i){
						ans--;
					}
			}
		}
		for(int i=ans;i>=1;i--){
			sum*=ans%MDO;
		}
		cout<<ans;
		return 0;
	}
	cout<<m;
	return 0;
}
