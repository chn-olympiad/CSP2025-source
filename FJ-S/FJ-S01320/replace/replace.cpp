#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2],a,a_,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>a>>b;
		ans=0;
		a_=a; 
		for(int i=1,x;i<=n;i++){
//			cout<<s[i][1].size()<<" ";
			if(a.find(s[i][0])<a.size()){
				x=a.find(s[i][0]);
				a.replace(x,s[i][1].size(),s[i][1]);
				if(a==b) ans++;
			}
			a=a_;
//			cout<<a<<endl;
		}
		cout<<ans<<endl;
	}
}

