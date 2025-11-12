#include<bits/stdc++.h>
using namespace std;
int n,i,q,j,sum=0;
string s[10001][3],t[10001][3],x,y,z;
bool tf=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    for(j=1;j<=q;j++) cin>>t[j][1]>>t[j][2];
    for(j=1;j<=q;j++){
        if(t[j][1].size() != t[j][2].size()){
            cout<<0<<endl;
            continue;
        }
        else{
            for(i=0;i<t[j][1].size();i++){
                if(t[j][1][i] == t[j][2][i]) tf=1;
                if(tf) break;
            }
            if(tf){
                sum++;

            }
            tf=0;
        }
        cout<<sum<<endl;
        sum=0;
    }
    cout<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
