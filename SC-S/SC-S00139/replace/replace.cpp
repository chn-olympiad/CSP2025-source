#include<bits/stdc++.h>
using namespace std;


const int maxn=2e5+10;
const unsigned long long base=131ll;

unsigned long long pre1[maxn],pre2[maxn],_base[maxn];
string s1,s2;
struct node{
    unsigned long long lda,rda;
    int len;
}qwq[maxn];
bool cmp(node a,node b){
    return a.len<b.len;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    int cnt=0;
    _base[0]=1;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        if(s1==s2) cnt++;
        qwq[i].len=s1.size();
        unsigned long long v1=0,v2=0;
        for(int i=0;i<s1.size();i++){
            v1=v1*base+s1[i],v2=v2*base+s2[i];
        }
        _base[i]=_base[i-1]*base;
        qwq[i].lda=v1,qwq[i].rda=v2;
    }
    sort(qwq+1,qwq+1+n,cmp);
    for(int p=1;p<=q;p++){
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            printf("0\n");
            continue;
        }
        int l=0,r=s1.size()-1;
        while(s1[l]==s2[l]) l++;
        while(s1[r]==s2[r]) r--;
        for(int i=0;i<s1.size();i++){
            pre1[i]=(i==0?s1[i]:pre1[i-1]*base+s1[i]);
            pre2[i]=(i==0?s2[i]:pre2[i-1]*base+s2[i]);
        }
        int _len=s1.size();
        int ans=0;
        for(int i=n;i>=1;i--){
            if(qwq[i].len<r-l+1) break;
            int len=qwq[i].len;
			unsigned long long lda=qwq[i].lda,rda=qwq[i].rda;
            for(int j=max(0,r-len+1);j<=min(_len-len,l);j++){
                if((pre1[j+len-1]-(j==0?0:pre1[j-1])*_base[len]==lda)&&(pre2[j+len-1]-(j==0?0:pre2[j-1])*_base[len]==rda)) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}