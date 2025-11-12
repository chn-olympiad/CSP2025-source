#include <bits/stdc++.h>
using namespace std;
long long t,n,hn;
long long a,b,c;
long long ca,cb,cc,ans;
long long be[500010],le[500010];
/*
first problem is ez right?
buff Kenji and Ziggy pls supercell
//freopen()
culb.in
club1.in
luogu uid=640552
WOHENTUPAILIE :\

wochangchangzhuiyiguoqu

才注意到有中文输入法
*/
void dest(int id){
    for(int i=1;i<=n;i++){
        if(be[i]!=id){
            le[i]=200000000010ll;
        }
    }
    sort(le+1,le+1+n);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){//duocebuqingkong baolinglianghanglei
        cin>>n;
        hn=n/2;
        ca=0;
        cb=0;
        cc=0;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            if(a>b&&a>c){
                ans+=a;
                be[i]=1;
                ca++;
                le[i]=a-max(b,c);
            }else{
                if(b>c){
                    ans+=b;
                    be[i]=2;
                    cb++;
                    le[i]=b-max(a,c);
                }else{
                    ans+=c;
                    be[i]=3;
                    cc++;
                    le[i]=c-max(a,b);
                }
            }
        }
        if(ca>hn){
            dest(1);
        }else{
            if(cb>hn){
                dest(2);
            }else{
                if(cc>hn){
                    dest(3);
                }
            }
        }
        hn=max(ca,max(cb,cc))-hn;
        for(int i=1;i<=n;i++){
            if(hn<=0)break;
            ans-=le[i];
            hn--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
