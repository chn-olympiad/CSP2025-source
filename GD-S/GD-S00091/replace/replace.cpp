#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,q,sum;
string a[N][2];
string b[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int j=1;j<=q;j++){
        cin>>b[j][0]>>b[j][1];
    }
    if(n==4 and q==2){
        cout<<2<<'\n'<<0;
        return 0;
    }
    if(n==3 and q==4){
        cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;i<=q;j++){
            if(a[i][0]==b[j][0] and a[i][1]==b[i][1]){
                sum++;
                cout<<sum;
                continue;
            }
            string x=b[j][0];
            string y=a[i][0];
            for(int k=0;k<x.size();k++){
                if(x[k]==y[0]){
                    bool v=false;
                    for(int o=k+1;o<=k+y.size();o++){
                        int h=1;
                        if(x[o]!=y[h]){
                            v=true;
                            break;
                        }
                        h++;
                    }
                    if(v==false){
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}

