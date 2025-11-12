#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        if(i==m){
            n+=1;
            for(int j=m;i>=1;j--){
                if(i==1){
                    n+=1;
                }
            }
        }

        cout<<n<<m;
    }

}
