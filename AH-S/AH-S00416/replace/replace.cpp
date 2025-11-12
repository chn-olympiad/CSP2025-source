#include <bits/stdc++.h>
using namespace std;
vector<int >a[5000005],b[5000005],c[5000005],d[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int id1=0,id2=0;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                id1=j;
            }
        }
        for(int j=0;j<s2.size();j++){
            if(s2[j]=='b'){
                id2=j;
            }
        }
        if(id2-id1>=0){
            a[id2-id1].push_back(id1);
            b[id2-id1].push_back(s1.size()-id2);
        }
        else{
           c[id1-id2].push_back(id2);
            d[id1-id2].push_back(s1.size()-id1);
        }
    }
    while(q--){
    string t1,t2;
    cin>>t1>>t2;
        int id1=0,id2=0,ans=0;
        for(int i=0;i<t1.size();i++){
            if(t1[i]=='b'){
                id1=i;
            }
        }
        for(int i=0;i<t2.size();i++){
            if(t2[i]=='b'){
                id2=i;
            }
        }
        if(id2-id1>=0){
            for(int i=0;i<a[id2-id1].size();i++){
                if(id1>=a[id2-id1][i]&&t1.size()-id2>=b[id2-id1][i]){
                    ans++;
                }
            }
        }
        else{
            for(int i=0;i<c[id1-id2].size();i++){
                if(id2>=c[id1-id2][i]&&t1.size()-id1>=d[id1-id2][i]){
                    ans++;
                }
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
