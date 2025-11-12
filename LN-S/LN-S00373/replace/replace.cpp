//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    char a1,b1;
    int a[n+1][2][2],b[q+1][2][2];
    string s1[n+1][2],s2[q+1][2];
    bool sure=false;
    for(int i=1;i<=n;i++){

        cin>>s1[i][0]>>s1[i][1];
        if(s1[i][0].length()>=3){
            a1=s1[i][0][1];
            b1=s1[i][0][0];

            if(s1[i][0][2]==b1){
                char t=b1;
                b1=a1;
                a1=t;
            }
            sure=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s2[i][0]>>s2[i][1];
        if(s2[i][0].length()>=3&&sure==0){
            a1=s2[i][0][1];
            b1=s2[i][0][0];
            if(s2[i][0][2]==b1){
                char t=b1;
                b1=a1;
                a1=t;
            }
            sure=1;
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=0;j<=1;j++){
            for(int x=0;x<=s2[i][j].length();x++){
                if(s1[i][j][x]==b1){
                    a[i][j][0]=x;
                    a[i][j][1]=s2[i][j].length()-x-1;
                }
            }

        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1;j++){
            for(int x=0;x<=s1[i][j].length();x++){
                if(s1[i][j][x]==b1){
                    a[i][j][0]=x;
                    a[i][j][1]=s1[i][j].length()-x-1;

                    break;
                }
            }

        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
            if(a[j][0][0]<=b[i][0][0]&&a[j][0][1]<=b[i][0][1]){
                if(b[i][0][0]+a[j][1][0]-a[j][0][0]==b[i][1][0]&&b[i][0][1]-a[j][1][0]+a[j][0][0]==b[i][1][1]){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}
