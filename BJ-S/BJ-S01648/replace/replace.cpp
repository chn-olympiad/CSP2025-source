#include<bits/stdc++.h>
using namespace std;
struct node{
    string s1,s2;
}a[100005];
int n,q,ans;
string t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    while(q--){
        ans=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            printf("0\n");
            continue;
        }
        for(int i=0;i<t1.size();i++){
            for(int j=1;j<=n;j++){
                bool ok=1;
                if(i+a[j].s1.size()<=t1.size()){
                    for(int k=0;k<t1.size();k++){
                        if(k>=i && k<i+a[j].s1.size()){
                            if(t1[i+k]!=a[j].s1[k] || t2[i+k]!=a[j].s2[k]){
                                ok=0;
                                break;
                            }
                        }
                        else{
                            if(t1[k]!=t2[k]){
                                ok=0;
                                break;
                            }
                        }
                    }
                }
                else continue;
                if(ok){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
