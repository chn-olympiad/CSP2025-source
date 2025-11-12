#include<bits/stdc++.h>
using namespace std;
int ns,q;
const int N=2e5+5;
const long long P1=1e9+7,P2=998244353;
struct hsht{
    long long val1,val2;
    friend hsht operator+(const hsht&x1,const hsht&x2){
        return hsht{(x1.val1+x2.val1)%P1,(x1.val2+x2.val2)%P2};
    }
    friend hsht operator-(const hsht&x1,const hsht&x2){
        return hsht{(x1.val1-x2.val1+P1)%P1,(x1.val2-x2.val2+P2)%P2};
    }
    friend hsht operator*(const hsht&x1,const hsht&x2){
        return hsht{x1.val1*x2.val1%P1,x1.val2*x2.val2%P2};
    }
    friend bool operator==(const hsht&x1,const hsht&x2){
        return x1.val1==x2.val1&&x1.val2==x2.val2;
    }
};
const hsht Base={29,37};
const int Lst=5e6+5;
hsht Basepow[Lst];
vector<hsht>S[N][2];
int lenS[N];
hsht gethsh(vector<hsht>::iterator vi,const int&l,const int&r){
    return *(vi+r)-*(vi+l-1)*Basepow[r-l+1];
}
vector<hsht>T[2];
int lenT;
typedef long long ll;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ns>>q;
    string Stri[2];
    int lenStot=0;
    for(int si=1;si<=ns;++si){
        cin>>Stri[0]>>Stri[1];
        lenS[si]=Stri[0].size();
        Stri[0].insert(Stri[0].begin(),' ');
        Stri[1].insert(Stri[1].begin(),' ');
        S[si][0].resize(lenS[si]+1);
        S[si][1].resize(lenS[si]+1);
        S[si][0][0]=S[si][1][0]={0,0};
        for(int i=1;i<=lenS[si];++i){
            S[si][0][i]=S[si][0][i-1]*Base+hsht{Stri[0][i]-'a'+1,Stri[0][i]-'a'+1};
            S[si][1][i]=S[si][1][i-1]*Base+hsht{Stri[1][i]-'a'+1,Stri[1][i]-'a'+1};
        }
        lenStot+=lenS[si];
    }
    Basepow[0]={1,1};
    for(int i=1;i<=lenStot;++i){
        Basepow[i]=Basepow[i-1]*Base;
    }
    int fp,lp;
    ll ans;
    int Tfp,Tlp;
    for(int qii=1;qii<=q;++qii){
        cin>>Stri[0]>>Stri[1];
        if(Stri[0].size()!=Stri[1].size()){
            cout<<"0\n";
            continue;
        }
        lenT=Stri[0].size();
        Stri[0].insert(Stri[0].begin(),' ');
        Stri[1].insert(Stri[1].begin(),' ');
        T[0].resize(lenT+1);
        T[1].resize(lenT+1);
        T[0][0]=T[1][0]={0,0};
        fp=lp=0;
        for(int i=1;i<=lenT;++i){
            T[0][i]=T[0][i-1]*Base+hsht{Stri[0][i]-'a'+1,Stri[0][i]-'a'+1};
            T[1][i]=T[1][i-1]*Base+hsht{Stri[1][i]-'a'+1,Stri[1][i]-'a'+1};
            if(Stri[0][i]!=Stri[1][i]){
                if(!fp){
                    fp=i;
                }
                lp=i;
            }
        }
        ans=0;
        for(int si=1;si<=ns;++si){
            if(lenS[si]<lp-fp+1){
                continue;
            }
            for(int i=1;i+lp-fp<=lenS[si];++i){
                if(gethsh(T[0].begin(),fp,lp)==
                    gethsh(S[si][0].begin(),i,i+lp-fp)
                &&gethsh(T[1].begin(),fp,lp)==
                    gethsh(S[si][1].begin(),i,i+lp-fp)
                &&i<=fp&&lenS[si]-(i+lp-fp)<=lenT-lp){
                    Tfp=fp-i+1;
                    Tlp=lp-(i+lp-fp)+lenS[si];
                    if(gethsh(T[0].begin(),Tfp,Tlp)==
                        gethsh(S[si][0].begin(),1,lenS[si])
                    &&gethsh(T[1].begin(),Tfp,Tlp)==
                        gethsh(S[si][1].begin(),1,lenS[si])){
                        ++ans;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}