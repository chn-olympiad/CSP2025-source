#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q;
struct node{
    string a,b;
}s[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        cin>>s[i].a>>s[i].b;
    while(q--){
        string ta,tb;
        set<string>ans;
        cin>>ta>>tb;
        //for(int i=1;i<=n;i++){
            //for(int j=0;j<ta.size()-s[i].a.size()-1;j++){
                //string jq=ta.substr(j,s[i].a.size()),bf=ta;
                //if(jq==s[i].a){
                    //ta.insert(j+1,s[i].b);
                    //ta.erase(j+s[i].b.size(),s[i].a.size());
                    //if(ta==tb)
                        //cnt++;
                    //ta=bf;
                //}
            //}
        //}
        for(int i=0;i<ta.size();i++){
            for(int j=1;j<=ta.size()-i+1;j++){
                string rp=ta.substr(i,j),bf=ta;
                //cout<<rp<<endl;
                for(int k=1;k<=n;k++){
                    if(rp==s[k].a){
                        ta.insert(i,s[k].b);
                        ta.erase(i+s[k].b.size(),s[k].a.size());
                        if(ta==tb)
                            ans.insert(rp);
                        ta=bf;
                    }
                }
            }
        }
        printf("%lld\n",ans.size());
    }
    return 0;
}
