#include<bits/stdc++.h>
using namespace std;
int n,q,s[200002],w[200002],z[200002];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int a1=0,b1=0;
        for(int j=0;j<a.size();j++){
            if(a[j]=='b'){
                a1=j+1;
                w[i]=j;
                z[i]=a.size()-a1;
            }
        }
        for(int j=0;j<a.size();j++){
            if(b[j]=='b'){
                b1=j+1;
            }
        }
        s[i]=a1-b1;
    }
    for(int i=1;i<=q;i++){
        int t=0;
        cin>>a>>b;
        int a1=0,b1=0,w1=0,z1=0;
        for(int j=0;j<a.size();j++){
            if(a[j]=='b'){
                a1=j+1;
                w1=j;
                z1=a.size()-a1;
            }
        }
        for(int j=0;j<a.size();j++){
            if(b[j]=='b'){
                b1=j+1;
            }
        }
        int c=a1-b1,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]==c&&w1>=w[i]&&z1>=z[i]) {
                ++cnt;
 //           cout<<i<<" yes"<<endl;
            }
    //        else cout<<i<<" no"<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
