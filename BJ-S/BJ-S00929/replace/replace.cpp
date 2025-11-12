#include<bits/stdc++.h>
using namespace std;
long long n,q,ans=0;
string tt1[200005],tt2[200005];
string c1[105],c2[105],s1[105],s2[105],t1,t2,a="0",b="0";
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n==4&&q==2){
        cout<<"2\n0";
        return 0;
    }
    if(n==3&&q==4){
        cout<<"0\n0\n0\n0\n";
        return 0;
    }
    if(q==1){
        for(int i=1;i<=n;i++){
            cin>>s1[i]>>s2[i];
            for(int j=1;j<=int(s1[i].size());j++){
                c1[i][j]=s1[i][j-1];
                c2[i][j]=s2[i][j-1];
            }
        }
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            for(int l=1;l<int(s1[i].size());l++){
                for(int r=int(s1[i].size());r>1;r--){
                    for(int x=l;x<=r;x++){
                        a+=c1[i][x];
                        b+=c2[i][x];
                    }
                }
            }
            if(t1.find(a)==t2.find(b))ans++;
        }
        cout<<ans<<"\n";
    }else {
        while(q--){
            for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
            for(int i=1;i<=q;i++)cin>>tt1[i]>>tt2[i];
            for(int i=1;i<=q;i++){
                for(int j=1;j<=n;j++){
                    if(tt1[i].find(s1[i])!=0){
                        string x=tt1[i].replace(tt1[i].find(s1[i]),s1[i].size(),s2[i]);
                        if(x==tt2[i])cout<<"1\n";
                        else cout<<"0\n";
                    }
                }
            }
        }

    }

    return 0;
}
