#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[100000],b[100000];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int taski=1;taski<=q;taski++){
        string c,d;
        cin>>c>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<c.length();j++){
                int flag=1;
                for(int k=j;k<j+a[i].length();k++){
                    if(c[k]!=a[i][k-j])flag=0;
                }
                for(int k=j;k<j+b[i].length();k++){
                    if(d[k]!=b[i][k-j])flag=0;
                }
                string cc;
                cc=c;
                for(int k=j;k<j+a[i].length();k++){
                    cc[k]=b[i][k-j];
                }
                if(cc!=d)flag=0;
                ans+=flag;
            }
        }
        cout<<ans;
    }
}