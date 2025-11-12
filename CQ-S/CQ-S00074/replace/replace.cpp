#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e6+5;
int n,m,ans[N];
string a[N],b[N],s,t;
int solve(string &s,string &t){
    if(s.size()!=t.size()) return 0;
    for(int i=1;i<=n;i++){
        if(a[i].size()>s.size()) continue;
        for(int j=1;j+a[i].size()<=s.size();j++){
            if(s.substr(j-1,a[i].size())==a){

            }
        }
    }
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s>>t;
        cout<<solve(s,t)<<'\n';
    }
	return 0;
}