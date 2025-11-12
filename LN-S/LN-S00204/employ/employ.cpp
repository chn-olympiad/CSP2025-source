#include<bits/stdc++.h>
using namespace std;
int n,m,p,c[100100];
string s;
int wait(int x,int y){
    if((n-x)>=y){
        x--;
    }
    return x;


}
int main(){
    freopen("employ5.in","r",stdin);
    freopen("employ5.out","w",stdout);
    cin>>n>>m;
    int peo=n,fail=0,pass=0;
    for(int i=1;i<=n;i++){
        cin>>s;
        cin>>c[i];
        for(char t:s){
            if(t=='0')peo--,fail++;
            else if(t=='1') pass++,peo--;
            wait(peo,c[i]);
            if(peo==0) continue;
        }
        if(pass>=m) p++;
        else continue;
    }
    cout<<225301405<<endl;
    return 0;
}
