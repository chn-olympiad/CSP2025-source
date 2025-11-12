#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
struct ss{
    string s,t;
    vector<int> nxts,nxtt;
    int diflen=0;
    string dif1="",dif2="";
}a[200005];
void work(vector<int> &nxt,string s){
    int len=s.size();
    s=" "+s;
    nxt.resize(s.size()+3);
    nxt[0]=0;
    for(int i=2,j=0;i<=len;i++){
        while(j>0&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
int f[5000005];
int solve(vector<int> nxt,string s,string t,string ns,string nt){//t wang s shang pipei
    int res=0;
    int lens=s.size(),lent=t.size();
    s=" "+s;
    t=" "+t;
    for(int i=1,j=0;i<=lens;i++){
        while(j>0&&s[i]!=t[j+1])j=nxt[j];
        if(s[i]==t[j+1])j++;
        f[i]=j;
        if(j==lent)res++;
    }
    return res;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].t;
        work(a[i].nxts,a[i].s);
        work(a[i].nxtt,a[i].t);
        for(int j=1;j<=a[i].s.size();j++){
            while(a[i].s[j-1]!=a[i].t[j-1]){
                a[i].diflen++;
                a[i].dif1+=a[i].s[j-1];
                a[i].dif2+=a[i].t[j-1];
                j++;
            }
        }
    }
    for(int i=1;i<=q;i++){
        ss x;
        cin>>x.s>>x.t;
        int sum=0;
        for(int j=1;j<=x.s.size();j++){
            while(x.s[j-1]!=x.t[j-1]){
                x.diflen++;
                x.dif1+=x.s[j-1];
                x.dif2+=x.t[j-1];
                j++;
            }
        }
        //work(x.nxts,x.s);
        //work(x.nxts,x.s);
        ll ans=0;
        for(int j=1;j<=n;j++){
            if(x.s.size()<a[j].s.size())continue;
            if(x.diflen==a[j].diflen&&x.dif1==a[j].dif1&&x.dif2==a[j].dif2)ans++;

        }
        printf("%lld\n",ans);
    }
}
