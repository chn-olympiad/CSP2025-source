#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,vector<int> >iden;
int n,q,ans,l;
string s1[200005],s2[200005],t1,t2,e1,e2;
pair<string,string>dif;
pair<string,string> getdiff(string a,string b){
    int s=0,t=a.length()-1;
    for(;a[s]==b[s];s++);
    for(;a[t]==b[t];t--);
    string res1="",res2="";
    for(int i=s;i<=t;i++){
        res1+=a[i];
        res2+=b[i];
    }
    return make_pair(res1,res2);
}
string cuts(string a,int s,int t){
    string res="";
    for(int i=s;i<=t;i++)res+=a[i];
    return res;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        iden[getdiff(s1[i],s2[i])].push_back(i);
    }
    while(q--){
        ans=0;
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<endl;
            continue;
        }
        dif=getdiff(t1,t2);
        for(int i=0;i<iden[dif].size();i++){
            e1=s1[iden[dif][i]];
            l=s1[iden[dif][i]].length();
            for(int j=0;j+l-1<t1.length();j++){
                if(cuts(t1,j,j+l-1)==e1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
