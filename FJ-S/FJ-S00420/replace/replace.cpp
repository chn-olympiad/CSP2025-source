#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
typedef long long ll;
int n,q;
string s[N][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	int ans=0;
	string t,t1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			ans++;
		}
	}
	while(q--){
		cin>>t>>t1;
		cout<<ans-q<<endl;
	}
	
	return 0;
}

