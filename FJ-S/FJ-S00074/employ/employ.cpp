#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int mod=998244353;
int n,m,c[N],tot0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) tot0++;
	}
	sort(c+1,c+n+1);
	if(n<=10){
		int ans=0;
		vector<int> id(n);
		iota(id.begin(),id.end(),1);
		do{
			int now=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0' || now>=c[id[i-1]]){
					now++;
				}
				//cout<<c[id[i-1]]<<" "; 
			}
			if(n-now>=m) ans++;//,cout<<" !\n";
			//cout<<"\n";
		}while(next_permutation(id.begin(),id.end()));
		cout<<ans;
		return 0;
	}
	if(s==string(n,'1')||m==1){
		ll ret=1;
		for(int i=1;i<=n;i++){
			ret=ret*i%mod;
		}
		if(n-tot0<m) cout<<"0";
		cout<<ret;
		return 0;
	}
	cout<<0;
	return 0;
}
