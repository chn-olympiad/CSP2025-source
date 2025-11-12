#include<bits/stdc++.h>
using namespace std;

int n,q,m;
map<pair<string,string> ,int> mp;
int ans;
int l,r;
string a,b;
string mid1,mid2,nowl,nowr;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i <= n;i++){
        cin>>a>>b;
        mp[{a,b}]++;
    }
    while(q--){
        cin>>a>>b;
        m = a.size();
        l = r = ans = 0;
        mid1 = mid2 = nowl = "";
        a = " " + a;
        b = " " + b;
        for(int i = 1;i <= m;i++){
            if(a[i] != b[i]){
                l = i;
                break;
            }
        }
        for(int i = m;i >= 1;i--){
            if(a[i] != b[i]){
                r = i;
                break;
            }
        }
        for(int i = l;i <= r;i++){
            mid1 += a[i];
            mid2 += b[i];
        }
        for(int i = l;i >= 1;i--){
            if(i != l) nowl = a[i] + nowl;
            nowr = "";
            for(int j = r;j <= m;j++){
                if(j != r) nowr += a[j];
                ans += mp[{nowl + mid1 + nowr,nowl + mid2 + nowr}];
            }
        }
        cout<<ans<<endl;
    }
}
