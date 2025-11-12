#include<bits/stdc++.h>
using namespace std;
int n,q,cnt=0;
string r[200010][2];
void check(string t1,string t2){
    for(int i=0;i<t1.size();i++){
        for(int j=1;j<=n;j++){
            bool sign=1;
            for(int a=0;a<r[j][0].size();a++){
                if(r[j][0][a]!=t1[i+a]){
                    sign=0;
                    break;
                }
            }
            if(sign){
                string t3=t1;
                for(int a=0;a<r[j][0].size();a++){
                    t3[i+a]=r[j][1][a];
                }
                if(t3==t2)cnt++;
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>r[i][0]>>r[i][1];
    for(int ttt=1;ttt<=q;ttt++){
        string t1,t2;
        cin>>t1>>t2;
        check(t1,t2);
        cout<<cnt<<endl;
        cnt=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
