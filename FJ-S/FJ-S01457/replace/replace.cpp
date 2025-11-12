#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<string> s(n+1);
    vector<string> s2(n+1);
    for(int i=1;i<=n;i++){
    	cin>>s[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			if(s[i]==t1&&s2[i]==t2){
				ans++;
				continue;
			}	
		}cout<<ans<<endl;
	}
	return 0;
}
