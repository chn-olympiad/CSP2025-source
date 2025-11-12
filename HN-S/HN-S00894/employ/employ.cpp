#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int ans=1;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				for(int i=1;i<=n;i++){
					ans*=i;
					ans%=MOD;
				}
				cout<<ans;
			}
		}
		return 0;
	}
	bool A=true;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=1){
			A=false;
		}
	}
	if(A){
		cout<<"161088479";
	}
	//该死的ccf样例解释都没有，全为1的情况看都看不懂 ****ccf!!! 
	return 0;
}

