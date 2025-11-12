#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,ans1=1,ans2=1;
    cin>>a;
    for(int i=1;i<n*m;++i){
        int b;
        cin>>b;
        if(b>a){
            if(ans1%2==1){
                if(ans2<n){
                    ans2+=1;
                }
                else{
                    ans1+=1;
                }
            }
            else{
                if(ans2>1){
                    ans2-=1;
                }
                else{
                    ans1+=1;
                }
            }
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
