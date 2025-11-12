#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int v[3]={};
        for(int i = 1;i<=n;i++){
            int abc[3]={};
            cin>>abc[0]>>abc[1]>>abc[2];
            sort(abc,abc+3,cmp);
            if(v[0]>n/2){
                if(v[1]>n/2){
                    sum+=abc[2];
                    v[2]++;
                }else{
                    sum+=abc[1];
                    v[1]++;
                }
            }else{
                sum+=abc[0];
                v[0]++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
