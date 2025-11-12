#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
    string s1,s2;
}a[N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
    while(q--){
            int cnt=0;
        string t1,t2;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            string s=t1;
            int p=t1.find(a[i].s1);
            if(p==-1) continue;
            string t=a[i].s2;
            for(int j=0;j<t.size();j++){
                s[p+j]=t[j];
            }
            if(s==t2) cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
