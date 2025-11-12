#include<bits/stdc++.h>
using namespace std;
struct huan{
    string l,r;
    int len;
};
bool yy[5000005]={0};
huan hu[200005];
string t1,t2;
bool cmp(huan a,huan b){
    return a.len>b.len;
}
string pjres="";
void pj(int a,int b,int ii){
    pjres="";
    for(int i=0;i<a;i++){
        pjres+=t1[i];
    }
    for(int i=a;i<=b;i++){
        pjres+=hu[ii].r[i-a];
    }
    for(int i=b+1;i<t1.length();i++){
        pjres+=t1[i];
    }
}
bool bj(){
    for(int i=0;i<t2.length();i++){
        if(t2[i]!=pjres[i]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,res=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>hu[i].l>>hu[i].r;
        hu[i].len=hu[i].l.length();
    }
    sort(hu+1,hu+n+1,cmp);
    int beg,en,cha;
    for(int k=1;k<=q;k++){
        cin>>t1>>t2;
        for(int i=0;i<t1.length();i++){
            if(t1[i]!=t2[i]){
                beg=i;
                break;
            }
        }
        for(int i=t1.length()-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                en=i;
                break;
            }
        }
        cha=en-beg+1;
        for(int i=1;i<=n;i++){
            if(hu[i].len<cha) break;
            for(int j=0;j<t1.length()-hu[i].len+1;j++){
                pj(j,j+hu[i].len-1,i);
                if(bj()){
                    res++;
                    break;
                }
            }
        }
        cout<<res<<endl;
        res=0;
        t1=t2="";
    }
    return 0;
}
