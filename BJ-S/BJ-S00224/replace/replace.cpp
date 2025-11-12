#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
pair<string,string> a[200005];
bool sp;
void SOLVE(){
    int l[200005];
    int r[200005];
    for(int i=1;i<=n;i++){
        int j=a[i].first.size();
        while(a[i].first[j]!='b' && a[i].second[j]!='b') j--;
        l[i]=a[i].first.size()-j;
        int k=0;
        while(a[i].first[k]!='b' && a[i].second[k]!='b') k++;
        r[i]=k;
    }
    while(m--){
        int ans=0;
        cin>>s1>>s2;
        int j=s1.size();
        while(s1[j]!='b' && s2[j]!='b') j--;
        j=s1.size()-j;
        int k=0;
        while(s1[k]!='b' && s2[k]!='b') k++;
        for(int i=1;i<=n;i++){
            if(l[i]<=j && r[i]<=k) ans++;
        }
        cout<<ans<<endl;
    }
    return;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        for(int j=0;j<a[i].first.size();j++){
            if(a[i].first[j]!='a' || a[i].first[j]!='b') sp=true;
            else if(a[i].second[j]!='a' || a[i].second[j]!='b') sp=true;
        }
    }
    if(sp==false){
        SOLVE();
        return 0;
    }
    while(m--){
        int ans=0;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            for(int j=1;j<=s1.size()-i;j++){
                //cout<<s1.substr(i,j)<<" "<<s2.substr(i,j)<<endl;
                if(s1.substr(i,j)==s2.substr(i,j)) continue;
                else if(s1.substr(0,i)!=s2.substr(0,i)) continue;
                else if(s1.substr(i+j,s1.size()-i-j)!=s2.substr(i+j,s1.size()-i-j)) continue;
                for(int k=1;k<=n;k++){
                    //cout<<a[k].first<<" "<<s1.substr(i,j)<<" "<<a[k].second<<" "<<s2.substr(i,j)<<endl;
                    if(a[k].first==s1.substr(i,j) && a[k].second==s2.substr(i,j)) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
