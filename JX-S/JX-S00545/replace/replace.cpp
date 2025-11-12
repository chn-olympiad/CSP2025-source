#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N=5e6+10;
const int base=131;
int n,q;
ll h[N];
char s1[N],s2[N];
map<PII,int> mp;
int main(){
    //update file name!!!
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1+1>>s2+1;
        int m=strlen(s1+1);
        int l=1,r=m;
        while(s1[l]==s2[l]&&l<=m) l++;
        if(l==m+1) continue;
        while(s1[r]==s2[r]&&r>=1) r--;
        ll v1=0,v2=0;
        for(int j=l;j<=r;j++){
            v1=(v1*base+s1[j]-'0');
            v2=(v2*base+s2[j]-'0');
        }
        mp[mk(v1,v2)]++;
    }
    for(int i=1;i<=q;i++){
        cin>>s1+1>>s2+1;
        int m1=strlen(s1+1),m2=strlen(s2+1);
        if(m1!=m2){
            cout<<0<<'\n';
            continue;
        }
        int m=m1;
        int l=1,r=m;
        while(s1[l]==s2[l]&&l<=m) l++;
        while(s1[r]==s2[r]&&r>=1) r--;
        ll v1=0,v2=0;
        for(int j=l;j<=r;j++){
            v1=(v1*base+s1[j]-'0');
            v2=(v2*base+s2[j]-'0');
        }
        cout<<mp[mk(v1,v2)]<<'\n';
    }
    return 0;
}