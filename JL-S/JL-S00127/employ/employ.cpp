#include<bits/stdc++.h>
using namespace std;
int n,m,d;
string s;
vector<int> c;
vector<int> cc;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin>>s;
    bool boo=1;
    for(int i=0;i<m;i++){
        if(s[i]=='0'){
            boo=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d);
        c.push_back(d);
    }
    if(boo==1){
        int x=1;
        for(int i=1;i<=n;i++) x*=i;
        printf("%d",x%998244353);
    }
    else printf("0");
    return 0;
}
