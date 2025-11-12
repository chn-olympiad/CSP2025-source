#include<bits/stdc++.h>
using namespace std;
int n,q,len;
pair<string,string>s[200005];
string t1,t2,y,tmp;
long long ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
    while(q--){
        cin>>t1>>t2;
        len=t1.length(),ans=0;
        for(int i=0;i<len;i++){
            y="";
            for(int j=i;j<len;j++){
                y+=t1[j];
                for(int k=1;k<=n;k++){
                    if(y==s[k].first){
                        tmp=t1;
                        for(int x=i;x<=j;x++)tmp[x]=s[k].second[x-i];
                        if(tmp==t2)ans++;
                        break;
                    }
                }
            }
        }cout<<ans<<'\n';
    }return 0;
}
