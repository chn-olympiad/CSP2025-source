// 显然我无法在考场推出 KMP。
#include<bits/extc++.h>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,q;
string s[200005][3],t1,t2;
string rep(string p,string t1,string t2){
    int pos=p.find(t1);
    if(pos==string::npos) return "You have no egg!";
    string p2=p;
    for(int i=pos;i<pos+t1.size();i++)p2[i]=t2[i-pos];
    return p2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
	}
	while(q--){
        cin>>t1>>t2;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=(rep(t1,s[i][1],s[i][2])==t2);
        }
        cout<<ans<<endl;
	}
	return 0;
}
