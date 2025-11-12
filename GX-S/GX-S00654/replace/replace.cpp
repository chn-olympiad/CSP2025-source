#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void read(T& a){
    a=0;char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();

    while(ch>='0' && ch<='9'){
        a=(a<<1)+(a<<3)+ch-'0';
        ch=getchar();
    }
}

int main(){
    cin.tie()->sync_with_stdio(false);
    cout.tie()->sync_with_stdio(false);
    #ifndef Db
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif
    int n,q; // n -> num of pair, q -> num of question
    cin>>n>>q;
    map<string,string>mp;
    unordered_map<string,bool>s;
    int maxlength=-1;
    for(int i=0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;
        maxlength=max(maxlength,(int)s1.size());
        mp[s1]=s2;
        for(int i=0;i<(int)s1.size();++i){
            s[s1.substr(0,i)]=false;
        }
        s[s1]=true;
    }
    for(int i=0;i<q;++i){
        int cnt=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<=n;++j){ // try replace from position 0
            if(s.count(s1.substr(j,1))){ //check if in s
                for(int k=0;k+j<=min((int)s1.size(),maxlength);++k){ // try k length to repalce
                    string rp=s1.substr(j,k);
                    if(s.count(rp)){
                        if(s[rp] && (s1.substr(0,j)+mp[rp]+s1.substr(j+k,s1.size()-k-j)==s2)){
                            cnt++;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

