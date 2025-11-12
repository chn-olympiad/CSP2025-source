#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a;
    int p=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(s[i]=='0'){
            p++;
        }
    }
    if(p==0){
        cout<<0;
    }else{
        cout<<p;
    }
return 0;
}
//Ren5Jie4Di4Ling5%
//5 3 4   3 5 1   5 3 4
//4 2 1   5 3 4   3 2 4
//3 5 1   3 2 4   4 2 1
//3 2 4   4 2 1   3 5 1
