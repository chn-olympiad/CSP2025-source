#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		string t1,t2,t3;
		cin>>t1>>t2;
		t1=' '+t1;
		for(int i=1;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				if(t1.substr(i,a[j].size())==a[j]){
					t3=t1;
					t3.replace(i,a[j].size(),b[j]);
					t3.erase(0,1);
					if(t3==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
