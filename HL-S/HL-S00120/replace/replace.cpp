#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string a,b;
pair<string,string> str[N];
int bfind1(pair<string,string> t) {
    int l=1,r=n;
    while(l<=r) {
        int mid=l+((r-l) >> 1);
        if(str[mid]>=t) r=mid-1;
        else l=mid+1;
    }
    if(str[l]!=t) return -1;
    else return l;
}
int bfind2(pair<string,string> t) {
    int l=1,r=n;
    while(l<=r) {
        int mid=l+((r-l) >> 1);
        if(str[mid]<=t) l=mid+1;
        else r=mid-1;
    }
    if(str[r]!=t) return -1;
    else return r;
}
pair<string,string> t;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        cin >> str[i].first >> str[i].second;
    }
    sort(str+1,str+n+1);
    while(q--) {
        cin >> a >> b;
        int len=a.length();
        int s=0x3f3f3f3f,e=0xc0c0c0c0;
        for(int i=0;i<len;i++) {
            if(a[i]!=b[i]) {
                s=min(s,i);
                e=max(e,i);
            }
        }
//        cout << "s=" << s << ",e=" << e << endl;
        long long ans=0;
        for(int i=0;i<=s;i++) {
            for(int j=e;j<len;j++) {
//                cout << "i=" << i << " j=" << j << endl;
                t=make_pair(a.substr(i,j-i+1),b.substr(i,j-i+1));
                int finds=bfind1(t),finde=bfind2(t);
                if(finds==-1 || finde==-1) continue;
                ans+=(finde-finds+1);
//                cout << "(" << i << "," << j << ") " << "by" << " " << str[finds].first << " and " << str[finds].second << " " << endl;
             }
        }
        printf("%lld\n",ans);
    }
    /*
    4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
    */
    return 0;
}
