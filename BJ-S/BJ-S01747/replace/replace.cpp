#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+3;
int n,q;
int a1[N],a2[N],a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    map<int,string>p1;
    map<int,string>p2;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(a1[i]=0;s1[a1[i]]!='b';a1[i]++){
        }
        for(a2[i]=0;s2[a2[i]]!='b';a2[i]++){
        }
        p1[i]=s1;
        p2[i]=s2;
        a[i]=a1[i]-a2[i];
    }
    int ans=0;
    while(q--){
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        if(s1.size()!=s2.size()){
            continue;
        }
        int b1,b2;
        for(b1=0;s1[b1]!='b';b1++){
        }
        for(b2=0;s2[b2]!='b';b2++){
        }
        for(int i=0;i<n;i++){
            if(b1>=a1[i]&&s1.size()-b1>=p1[i].size()-a1[i]&&b2>=a2[i]&&s2.size()-b2>=p2[i].size()-a2[i]&&b1-b2==a[i]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
