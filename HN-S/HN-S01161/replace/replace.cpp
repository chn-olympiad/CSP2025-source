// replace
#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-f;
    for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
    return f*x;
}
const int N=2e5+5;
int n,q;
string s[N][3];
int id[N];
const int p=29,mod=1e9+7;
using ui=unsigned int;
ui h[N][3];
ui turn(string t){
    ui res=0;
    for(char ch:t){
        res=(res*p%mod+ch-'0')%mod;
    }
    return res;
}
ui turn(string t,int first,int last){
    ui a=0,b=0;
    for(int i=first;i<last;i++){
        a=(a*p%mod+t[i]-'0')%mod;
    }
    return a;
}
int ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        h[i][1]=turn(s[i][1]);
        h[i][2]=turn(s[i][2]);
        id[i]=i;
    }
    sort(id+1,id+n+1,[](int a,int b){return s[a][1].size()>s[b][1].size();});
    while(q--){
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            printf("0\n");
            continue;
        }
        int tl=t1.size(),tr=0;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                tl=min(tl,i);
                tr=max(tr,i);
            }
        }
        int l=1,r=n,mid;
        while(l<r){
            mid=l+r+1>>1;
            if(s[mid][1].size()>=tr-tl+1)l=mid;
            else r=mid-1;
        }
        for(int j=1;j<=l;j++){
            int len=s[j][1].size();
            for(int i=0;i<t1.size();i++){
                if(i<=tl&&tr<=i+len-1){
                    if(turn(t1,i,i+len)==h[j][1]&&turn(t2,i,i+len)==h[j][2]){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}