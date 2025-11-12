#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int maxn=1e5+10;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string y1[maxn],y2[maxn];
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>y1[i]>>y2[i];
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            int sp=y1[i].size();
            for(int j=0;j<s1.size()-sp+1;j++){
                int len=s1.size();
                string h1=s1.substr(0,j);
                string h2=s2.substr(0,j);
                h1=h1.substr(0,j+1);
                h2=h2.substr(0,j+1);

                string t1=s1.substr(j+sp,len-1);
                string t2=s2.substr(j+sp,len-1);
                t1=t1.substr(0,len-1);
                t2=t2.substr(0,len-1);

                string xx=s1.substr(j,j+sp);
                string yy=s2.substr(j,j+sp);
                xx=xx.substr(0,sp);
                yy=yy.substr(0,sp);
                if(xx==y1[i]&&yy==y2[i]){
                    if(h1+y2[i]+t1==h2+yy+t2) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
