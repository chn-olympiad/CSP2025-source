#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a.find(s1[i]) != 18446744073709551615){
                int y=a.find(s1[i]);

                string c=a.substr(0,y);//x
                c+=s2[i];//y
                c+=a.substr(y+s1[i].size(),a.size()-y+s2[i].size());//z

                if(c==b)sum++;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
