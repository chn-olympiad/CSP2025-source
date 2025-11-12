#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
unordered_map<string,string>t;
set<int>y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        string a,b;
        cin >> a >> b;
        t[a]=b;
        y.insert(a.size());
    }
    while(q--){
        ans=0;
        string t1,t2;
        cin >> t1 >> t2;
        for(int i:y){
            int ct = i;
            if(ct>t1.size()){
                break;
            }
            for(int j = 0;j<=t1.size()-ct;j++){
                string a =t1.substr(j,ct);

                if(t[a]!=""){
                    string t3 = t1;
                    for(int k = j;k<j+ct;k++){
                        t3[k]=t[a][k-j];
                    }
                    ans+=(t2==t3);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
