#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
string s1[N],s2[N];
int n,q,ans,ik;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];

    }
    while(q--){
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            int j=0;
            while(1){
                int f1=t1.find(s1[i],j);
                if(f1==-1){
                    break;
                }
                int f2=t2.find(s2[i],j);
                j=f1+s1[i].size();
                if(f1==f2){
                    int t=1;
                    for(int k=0;k<f1;k++){
                        if(t1[k]!=t2[k]){
                            t=0;
                            break;
                        }
                    }
                    if(t){
                        for(int k=j;k<t1.size();k++){
                            if(t1[k]!=t2[k]){
                                t=0;
                                break;
                            }
                        }
                        if(t){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
