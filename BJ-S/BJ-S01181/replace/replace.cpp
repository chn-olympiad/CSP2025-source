#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct node{
 string s,t;
 int dl,dr;
}a[N];
bool cmp(node x,node y){
    if(x.dr-x.dl!=y.dr-y.dl||x.dl==y.dl&&x.dl==-1){
        return x.dr-x.dl<y.dr-y.dl;
    }
    for(int i=0;i<=x.dr-x.dl;++i){
        if(x.s[i]!=y.s[i]) return x.s[i]<y.s[i];//xiu
    }
    for(int i=0;i<=x.dr-x.dl;++i){
        if(x.t[i]!=y.t[i]) return x.t[i]<y.t[i];
    }
    if(x.s!=y.s) return x.s<y.s;
    return x.t<y.t;
}
int n,q,al,ar;
string ask[N][2],qu[2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i].s>>a[i].t;
        a[i].dl=-1;
        a[i].dr=1e9+5;
        for(int j=0;j<a[i].s.size();++j){
            if(a[i].dl==-1&&a[i].s[j]!=a[i].t[j]) a[i].dl=j;
            if(a[i].dl!=-1&&a[i].s[j]!=a[i].t[j]&&(j+1==a[i].s.size()||a[i].s[j+1]==a[i].t[j+1])) a[i].dr=j;
        }
    }
    while(q--){
        int ans=0,flg=0;
        cin>>qu[0]>>qu[1];
        al=-1;
        ar=1e9+5;
        for(int i=0;i<qu[0].size();++i){
            if(al==-1&&qu[0][i]!=qu[1][i]) al=i;
            if(al!=-1&&qu[0][i]!=qu[1][i]&&(i+1==qu[0].size()||qu[0][i+1]==qu[1][i+1])) ar=i;
        }
        for(int i=1;i<=n;++i){
            if(a[i].dr-a[i].dl!=ar-al) continue;
            if(a[i].dl>al||a[i].s.size()-a[i].dr>qu[0].size()-ar) continue;
            flg=0;
            for(int j=0;j<=ar-al;++j){
                if(a[i].s[a[i].dl+j]!=qu[0][al+j]||a[i].t[a[i].dl+j]!=qu[1][al+j]){
                    //cout<<j<<endl;
                    flg=1;
                    break;
                }
            }
            //cout<<"zhong"<<endl;
            if(flg==1) continue;
            for(int j=a[i].dl-1;j>=0;--j){
                if(a[i].s[j]!=qu[0][al-a[i].dl+j]||a[i].t[j]!=qu[1][al-a[i].dl+j]){
                    flg=1;
                    break;
                }
            }
            //cout<<"qian";
            if(flg==1) continue;
            for(int j=a[i].dr+1;j<a[i].s.size();++j){
                if(a[i].s[j]!=qu[0][ar-a[i].dr+j]||a[i].t[j]!=qu[1][ar-a[i].dr+j]){
                    //cout<<j;
                    flg=1;
                    break;
                }
            }

            if(flg==1){
                //cout<<"hou";
                continue;
            }
            ++ans;
        }
        cout<<ans<<endl;
    }


    return 0;
}
