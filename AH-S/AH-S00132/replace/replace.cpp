#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
const int maxq=2e5+5;

int ans=0;
int n,q;
string t1[maxn],t2[maxn];
string q1[maxq],q2[maxq];

void init(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>q1[i]>>q2[i];
    }
}

void sovle(int cnt){
    string a=q1[cnt];
    string b=q2[cnt];
    int match=0;
    int t;
    for(int i=1;i<=n;i++){
        match=0;
        for(int j=0;j<=a.size()-1;j++){
            if(a[j]==t1[i][match]) match++;
            if(match==t1[i].size()){
                t=match;
                for(;t!=0;t--){
                    swap(a[j],t2[i][t-1]);
                    j--;
                }
                if(a==b) ans++;
                for(;t<match;t++){
                    j++;
                    swap(a[j],t2[i][t]);
                }
                break;
            }
        }
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init();
    for(int i=1;i<=q;i++){
        ans=0;
        sovle(i);
        cout<<ans<<endl;
    }
    return 0;
}