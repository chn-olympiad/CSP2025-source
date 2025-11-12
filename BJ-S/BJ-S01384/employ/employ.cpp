#include <bits/stdc++.h>
using namespace std;

int c[510];

int main (){
//    freopen("employ.in","r",stdin);
//    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
//    cout<<"Cin OK!"<<endl;
    bool Apd=0;
    for(int i=0;i<n;i++){
        if(s[i]!='1') Apd=1;
    }
    if(Apd==0){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*i)%998244353;
        }
        printf("%d",ans);
    }else{
        printf("0");
    }

    return 0;
}