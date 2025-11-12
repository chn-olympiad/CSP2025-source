#include<bits/stdc++.h>
using namespace std;
int n,q,idx,ans;
string t1,t2,t3,p1,p2;
struct str{
    string s1,s2;
}s[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
    }
    //string d="qjdiejd";
    while(q--){
        cin>>t1>>t2;
        t3=t1;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(s[i].s1==s[i].s2){
                continue;
            }
            t3=t1;
            //cout<<"t3pre"<<t3<<endl;
            idx=t3.find(s[i].s1);
            //cout<<"idx"<<idx<<endl;
            if(idx==t3.size() || idx<0){
                continue;
            }
            if(idx>=1 && idx+s[i].s2.size()<=t3.size()-1){
                p1=t3.substr(0,idx);
                p2=t3.substr(idx+s[i].s2.size(),t3.size()-idx-s[i].s2.size());
                t3=p1+s[i].s2+p2;
            }
            else if(idx<1 && idx+s[i].s2.size()<=t3.size()-1){
                p2=t3.substr(idx+s[i].s2.size(),t3.size()-idx-s[i].s2.size());
                t3=s[i].s2+p2;
            }
            else if(idx>=1){
                p1=t3.substr(0,idx);
                t3=p1+s[i].s2;
            }
            else{
                t3=s[i].s2;
            }
            //cout<<idx<<" "<<p1<<" "<<p2<<endl;
            //p1=t3.substr(0,idx-1);
            //p2=t3.substr(idx+s[i].s2.size(),t3.size()-1);
            //t3=p1+s[i].s2+p2;
            //cout<<"s[i].s2 "<<s[i].s2<<" t3 "<<t3<<endl;
            if(t3==t2){
                ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
        idx=0;
    }
    return 0;
}
