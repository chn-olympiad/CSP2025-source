#include<bits/stdc++.h>
using namespace std;
long long n,q;
string dat[2000010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>dat[i][0]>>dat[i][1];
	} 
	while(q--){
		string f,t;
		cin>>f>>t;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=0;j+dat[i][0].size()-1<f.size();j++){
				if(f.substr(j,dat[i][0].size())==dat[i][0]){
//					cout<<1<<endl;
					if(f.substr(0,j)+dat[i][1]+f.substr(j+dat[i][0].size())==t) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
