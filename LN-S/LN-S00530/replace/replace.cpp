#include<bits/stdc++.h>
using namespace std;
typedef long long ll;   
const int N=2e5+10;
int n,q;
pair<string,string> rp[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>rp[i].first>>rp[i].second;
    while(q--){
        string t1,t2;
        ll sum=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(t1.find(rp[i].first)!=-1){
                for(int l=0;l<t1.size();l++){
                    string tmp="";
                    for(int r=l;r<t1.size()&&(r-l+1)<=rp[i].first.size();r++){
                        tmp+=t1[r];
                    }
                    if(tmp==rp[i].first){
                        string newt="";
                        for(int j=0;j<l;j++) newt+=t1[j];
                        newt+=rp[i].second;
                        for(int j=l+tmp.size();j<t1.size();j++) newt+=t1[j];
                        if(newt==t2) sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
//g++ -o test test.cpp -O2 -std=c++14 -static