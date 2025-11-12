#include<bits/stdc++.h>
using namespace std;
namespace YSJ{
    int n,q;
    string s1[200005],s2[200005];
    int main(){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
        while(q--){
            int sum=0;
            string t1,t2;
            cin>>t1>>t2;
            int x1,x2;
            for(int i=0;i<t1.size();i++){
                if(s1[i]!=s2[i]){
                    x1=i;
                }
            }
            for(int i=t1.size()-1;i>=0;i--){
                if(s1[i]!=s2[i]){
                    x2=i;
                }
            }
            for(int idx=1;idx<=n;idx++){
                int x=t1.find(s1[idx]);
                if(x<t1.size()){
                    string tmp=t1;
                    for(int i=x;i<x+s1[idx].size();i++){
                        tmp[i]=s2[idx][i-x];
                    }
                    // cerr<<tmp<<'\n';
                    if(tmp==t2){
                        sum++;
                        // cerr<<s1[idx]<<'\n';
                    }
                }
            //     for(int i=0;i<=s1[idx].size();i++){
            //         bool flag=0;
            //         for(int j=0;j<x2-x1+1;j++){
            //             if(s1[idx][i+j]!=t1[x1+j]){
            //                 flag=1;
            //                 break;
            //             }
            //         }
            //         if(!flag){
            //             for(int j=i-1;i>=0;j--){
            //                 bool 
            //             }
            //         }
            //     }
            }
            cout<<sum<<'\n';
        }
        return 0;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    return YSJ::main();
}