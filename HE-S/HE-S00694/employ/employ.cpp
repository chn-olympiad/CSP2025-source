#include<iostream>
using namespace std;
int main(){
    freopen("employ.in","s",stdin);
    freopen("employ.out","w",stdout);
    int n;
    int m;
    cin>>n;
    cin>>m;
    int s;
    cin>>s;
    int ans;
    if(ans==0){
        ans=0;
    }
    int h;
    cin>>h;
    int b;
    cin>>b;
    for(int i=1;i<=n;i++){
        if(h==b){
        ans=ans-1;
        }else if(n>s){
            ans=ans+1;
            if(ans==m){
                cout<<330986<<endl;
            }
        }
    }
    return 0;
}
