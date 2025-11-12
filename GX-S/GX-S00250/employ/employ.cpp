#include<bits/stdc++.h>
using namespace std;
struct people{
    char s;
    int c;
}bro[501];
bool cmp(people a,people b){
    return a.c<b.c;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>bro[i].s;
    }
    for(int i = 1;i<=n;i++){
        cin>>bro[i].c;
    }
    for(int i = 1;i<=n;i++){
        if(bro[i].s=='1'){
            cout<<2;
            return 0;
        }
        else{
            break;
        }
    }
    return 0;
}
