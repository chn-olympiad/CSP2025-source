#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n,m,tlen,ans;
struct node{
    string s1,s2;
    int l,r,len,ml;
}a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        a[i].len=a[i].s1.size();
        for(int j=0;j<a[i].len;j++){
            if(a[i].s1[j]=='b'){
                a[i].ml-=j;
                a[i].l=j,a[i].r=a[i].len-j-1;
            }
            if(a[i].s2[j]=='b') a[i].ml+=j;
        }
        //cout<<a[i].ml<<" "<<a[i].l<<" "<<a[i].r<<'\n';
    }
    while(m--){
        string t1,t2;
        cin>>t1>>t2;
        ans=0;
        int dest=0,pla;
        tlen=t1.size();
        for(int i=0;i<tlen;i++){
            if(t1[i]=='b')  dest-=i,pla=i;
            if(t2[i]=='b')  dest+=i;
        }
        //cout<<dest<<' '<<pla<<'\n';
        for(int i=1;i<=n;i++){
            if(a[i].ml!=dest)   continue;
            if(i-a[i].l<0 or i+a[i].r>=tlen)  continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3 3
aaba aaab
ab ba
aaab baaa
abaaa aaaba
aba baa
aaaba baaaa
*/
