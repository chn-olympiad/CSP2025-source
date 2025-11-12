#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q,cnt;
string s[200005][2],t[200005][2],T;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>t[i][0]>>t[i][1];
        cnt=0;
        int len=t[i][0].length();
        for(int qz=0;qz<n;qz++){
            for(int wz=0;wz<len;wz++){
                bool b=true;
                T=t[i][0];
                for(int j=0;j<s[qz][0].length();j++){
                    if(s[qz][0][j]!=t[i][0][wz+j]||s[qz][1][j]!=t[i][1][wz+j]){
                        b=false;
                    }
                    T[wz+j]=s[qz][1][j];
                }
                if(b==true&&T==t[i][1]){
                    cnt++;
                    //cout<<s[qz][0]<<"\n";
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
