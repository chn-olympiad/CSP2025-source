#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int x,y;
    cin>>x>>y;
    string s[3][10005];
    for(int i=0;i<x;i++){
        cin>>s[0][i];
        cin>>s[1][i];
    }
    for(int i=0;i<y;i++){
        string t1,t2;
        cin>>t1>>t2;
        int cnt=0;
        for(int st=0;st<t1.size();st++){
            for(int thz=0;thz<x;thz++){
                bool g=1;
                for(int j=0;j<t1.size();j++){
                    if(j>=st&&j<st+s[0][thz].size()){
                        if(s[1][thz][j-st]!=t2[j]){
                            g=0;
                            break;
                        }
                    }else{
                        if(t1[j]!=t2[j]){
                            g=0;
                            break;
                        }
                    }
                }
                if(g==1)cnt++;
            }
        }
        cout<<cnt;
        if(i!=y-1){
            cout<<endl;
        }
    }
    return 0;
}
