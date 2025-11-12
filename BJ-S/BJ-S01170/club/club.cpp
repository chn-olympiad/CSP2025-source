#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<node>s(n);
        vector<int>d(n);
        int ret=0,lena=0,lenb=0,lenc=0;
        for(int i=0;i<n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            if(max({s[i].a,s[i].b,s[i].c})==s[i].a){
                d[i]=1;
                ret+=s[i].a;
                lena++;
            }
            else if(max({s[i].a,s[i].b,s[i].c})==s[i].b){
                d[i]=2;
                ret+=s[i].b;
                lenb++;
            }
            else{
                d[i]=3;
                ret+=s[i].c;
                lenc++;
            }
        }
        if(lena>n/2||lenb>n/2||lenc>n/2){
            int achao=lena-n/2,bchao=lenb-n/2,cchao=lenc-n/2;
            vector<pair<int,int>>ab,bc,ac,ba,ca,cb;
            for(int i=0;i<n;i++){
                ab.push_back({s[i].a-s[i].b,i});
                ac.push_back({s[i].a-s[i].c,i});
                bc.push_back({s[i].b-s[i].c,i});
                ba.push_back({s[i].b-s[i].a,i});
                ca.push_back({s[i].c-s[i].a,i});
                cb.push_back({s[i].c-s[i].b,i});
            }
            sort(ab.begin(),ab.end());
            sort(ac.begin(),ac.end());
            sort(bc.begin(),bc.end());
            sort(ba.begin(),ba.end());
            sort(ca.begin(),ca.end());
            sort(cb.begin(),cb.end());
            int pos=0;
            while(achao>0){
                bool flag=d[ab[pos].second]==1&&bchao<0;
                if(flag){
                    if(d[ac[pos].second]==1&&cchao<0){
                        flag=(ab[pos].first<ac[pos].first);
                    }
                }
                if(d[ab[pos].second]==1&&bchao<0&&flag){
                    bchao++;
                    achao--;
                    ret-=ab[pos].first;
                    d[ab[pos].second]=2;
                }
                else if(d[ac[pos].second]==1&&cchao<0){
                    cchao++;
                    achao--;
                    ret-=ac[pos].first;
                    d[ac[pos].second]=3;
                }
                pos++;
            }
            pos=0;
            while(bchao>0){
                bool flag=d[bc[pos].second]==2&&cchao<0;
                if(flag){
                    if(d[ba[pos].second]==2&&achao<0){
                        flag=(bc[pos].first<ba[pos].first);
                    }
                }
                if(d[bc[pos].second]==2&&cchao<0&&flag){
                    bchao--;
                    cchao++;
                    ret-=bc[pos].first;
                    d[bc[pos].second]=3;
                }
                else if(d[ba[pos].second]==2&&achao<0){
                    bchao--;
                    achao++;
                    ret-=ba[pos].first;
                    d[ba[pos].second]=1;
                }
                pos++;
            }
            pos=0;
            while(cchao>0){
                bool flag=d[cb[pos].second]==3&&bchao<0;
                if(flag){
                    if(d[ca[pos].second]==3&&achao<0){
                        flag=(cb[pos].first<ca[pos].first);
                    }
                }
                if(d[cb[pos].second]==3&&bchao<0&&flag){
                    bchao++;
                    cchao--;
                    ret-=cb[pos].first;
                    d[cb[pos].second]=2;
                }
                else if(d[ca[pos].second]==3&&achao<0){
                    cchao--;
                    achao++;
                    ret-=ca[pos].first;
                    d[ca[pos].second]=1;
                }
                pos++;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
