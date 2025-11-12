#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,Xz=3e5;
vector<pair<int,int> > v[N];
string s1s,s2s;
void gt(int op){
    int x=s1s.find('b'),y=s2s.find('b');
    if(op==1){
        v[x-y+Xz].push_back({x,s1s.size()-(x+1)});
    }else{
        int ans=v[x-y+Xz].size();
        for(auto i:v[x-y+Xz]){
            if(x>=i.first&&s1s.size()-(x+1)>=i.second){
                continue;
            }
            ans--;
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if(q==1){
        if(n>1000){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>s1s>>s2s;
        gt(1);
    }
    for(int i=1;i<=q;i++){
        cin>>s1s>>s2s;
        gt(2);
    }
	return 0;
}
