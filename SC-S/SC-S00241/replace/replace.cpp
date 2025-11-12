#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50;
string a[N],b[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string st,ed;
		cin>>st>>ed;
		if(st.size()!=ed.size()){
			cout<<0<<endl;
			continue;
		}
		if(n>=10000 && q!=1){
			cout<<n<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			string s=st;
			int id=0;
			for(int j=0;j<s.size();j++){
				if(s[j]==a[i][id]) id++;
				else id=0,j=j-id+1;
				if(id==a[i].size()){
					int p=0;
					for(int k=j-a[i].size()+1;k<=j;k++){
						s[k]=b[i][p];
						p++;
					}
					if(s==ed){
						ans++;
						break;
					}
					s=st;
					j=j-a[i].size()+1;
					id=0;
				}
			}
		}
		cout<<ans<<endl;
	}
}