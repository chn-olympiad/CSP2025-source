#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[5000010],s2[5000010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    string sx,sy;
    while(q--){
        cin>>sx>>sy;
        long long ans=0;
        for(int len=1;len<=sx.size();len++){
            for(int i=0;(i+len-1)<sx.size();i++){
                int j=i+len-1;
                string sl,sr,st;
                for(int k=0;k<i;k++){
                    sl+=sx[k];
                }
                for(int k=i;k<=j;k++){
                    st+=sx[k];
                }
                for(int k=j+1;k<sx.size();k++){
                    sr+=sx[k];
                }
                for(int k=1;k<=n;k++){
                    if(st==s1[k]){
                        if(sl+s2[k]+sr==sy){
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
