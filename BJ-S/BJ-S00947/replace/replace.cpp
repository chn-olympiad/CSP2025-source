#include<bits/stdc++.h>
using namespace std;

int n,q;
string si[200010][2];

void getpai(string s,vector<int>& pai){
    s=' '+s;
    for(int i=2;i<s.length();i++){
        int j=pai[i-2];
        while(j!=0&&s[j+1]!=s[i]){
            j=pai[j-1];
        }
        if(j==0){
            pai[i-1]=(s[1]==s[i]);
            continue;
        }
        pai[i-1]=j+1;
    }
}

vector<int> kmp(string pt,string s){
    string ns=pt+'#'+s;
    vector<int> pai(ns.length()),res;
    getpai(ns,pai);
    for(int i=pt.length()+1;i<ns.length();i++){
        if(pai[i]==pt.length()-1){
            res.push_back(i-pt.length());
        }
    }
    return res;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>si[i][0]>>si[i][1];
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int l=-1,r=-1;
        bool flg=1;
        for(int j=0;j<t1.length();j++){
            if(t1[j]!=t2[j]){
                if(flg){
                    l=j;
                    flg=0;
                }
                r=j;
            }
        }
        if(l==r&&r==-1){
            cout<<n<<'\n';
            continue;
        }
        int now=0;
        for(int j=1;j<=n;j++){
            if(si[j][0].length()<(r-l+1)){
                continue;
            }
            vector<int> ot1,ot2;
            ot1=kmp(si[j][0],t1),ot2=kmp(si[j][1],t2);
            int lp,rp;
            lp=rp=0;
            bool flag=0;
            while(lp<ot1.size()&&rp<ot2.size()){
                while(lp<ot1.size()&&rp<ot2.size()&&ot1[lp]!=ot2[rp]){
                    while(lp<ot1.size()&&ot1[lp]<ot2[rp]){
                        lp++;
                    }
                    if(lp==ot1.size()){
                        break;
                    }
                    while(rp<ot2.size()&&ot1[lp]>ot2[rp]){
                        rp++;
                    }
                }
                if(lp>=ot1.size()||rp>=ot2.size()){
                    break;
                }
                if(ot1[lp]==ot2[rp]){
                    if(ot1[lp]-si[j][0].length()+1>l){
                        break;
                    }
                    if(ot1[lp]<r){
                        lp++;
                        continue;
                    }
                    flag=1;
                    break;
                }
            }
            if(flag){
                now++;
            }
        }
        cout<<now<<'\n';
    }

    return 0;
}
