#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100010][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int z1=s1.size(),z2=s2.size();
        if(z1!=z2){
            cout<<0;
            cout<<'\n';
            continue;
        }
        long long c=0;
        for(int i=0;i<z1;i++){
            for(int j=1;j<=n;j++){
                int z=s[j][0].size();
                if(i+z-1>z1) continue;
                string d1=s1.substr(i,z);
                string d2=s2.substr(i,z);
                if(d1==s[j][0]&&d2==s[j][1]){
                    string f1=s1.substr(0,i);
                    string f2=s2.substr(0,i);
                    string f3=s1.substr(i+z);
                    string f4=s2.substr(i+z);
                    if((i==0||f1==f2)&&(i+z==z-1||f3==f4)) c++;
                }
            }
        }
        cout<<c;
        cout<<'\n';
    }
    return 0;
}
