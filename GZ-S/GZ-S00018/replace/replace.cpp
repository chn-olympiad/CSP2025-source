//GZ-S00018 伍珈呈 贵州师范大学云岩实验中学
#include <bits/stdc++.h>
using namespace std;
map<int,int> num;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int ag,bg;
        for(int j=0;j<a.size();j++){
            if(a[j]=='b'){
                ag=j;
            }
            if(b[j]=='b'){
                bg=j;
            }
        }
        num[ag-bg]++;
    }
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        int ag,bg;
        for(int j=0;j<a.size();j++){
            if(a[j]=='b'){
                ag=j;
            }
            if(b[j]=='b'){
                bg=j;
            }
        }
        cout<<num[ag-bg]<<endl;
    }
    return 0;
}
