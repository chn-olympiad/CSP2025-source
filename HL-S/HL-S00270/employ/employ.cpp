#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string s;
int c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int p=n;
	cin>>s;
	int q=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			q++;
		}
	}
	if(q<m){
		cout<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			p--;
		}
	}
	for(int i=1;i<=p;i++){
		ans*=i;
		ans%=N;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
