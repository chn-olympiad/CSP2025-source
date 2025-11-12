#include <bits/stdc++.h>
using namespace std;
struct n{
    string qian;
    string hou;
}s[200000];
int main(){
    freopen ("replace.in","r",stdin);
    freopen ("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].qian;
        cin>>s[i].hou;
    }
    for(int i=1;i<=q;i++){
        int cnt=0;
        string qianq,houq;
        cin>>qianq>>houq;
        for(int j=1;j<=qianq.length();j++){
            if(strstr(s[j].qian,qianq)){
                if(strstr(s[j].hou,houq)){
                    cnt++;
                }
            }

        }
    }
    cout<<cnt<<endl;
    return 0;