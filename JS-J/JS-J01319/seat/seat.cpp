//remember:ctrl+s!!!
//ctrl+s!!!
//ctrl+s!!!
//baocun!!!
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int cj[105],r=0;
int main(){
    //ctrl+s!!!
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //quxiaozhushi:yiding     ctrl+s!!!

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>cj[i];
    }
    r=cj[0];
    sort(cj,cj+n*m+1,cmp);
   
    int tx=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){//->
            for(int i=1;i<=n;i++,tx++){
                if(cj[tx]==r){
                    cout<<j<<" "<<i;
                    return 0;
                }   
            }
        }
        else{//<-
            for(int i=n;i>0;i--,tx++){
                if(cj[tx]==r){
                    cout<<j<<" "<<i;
                    return 0;
                }   
            }
        }
        
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
//  g++ 1.cpp -o 1 -std=c++14